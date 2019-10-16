Public Class Form5
    'getting rid of the (X) button
    Private Const CP_NOCLOSE_BUTTON As Integer = &H200
    Protected Overloads Overrides ReadOnly Property CreateParams() As CreateParams
        Get
            Dim myCp As CreateParams = MyBase.CreateParams
            myCp.ClassStyle = myCp.ClassStyle Or CP_NOCLOSE_BUTTON
            Return myCp
        End Get
    End Property

    'Username variable from other form
    Dim User As String = Form1.txt_name.Text
    Dim bank As Integer = Form3.lbl_money.Text

    Private Sub Form5_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Page size and location on screen
        Size = New Size(1100, 860)
        Me.CenterToParent()
        'Getting rid of the maximise
        MaximizeBox = False
        'Username
        lbl_user.Text = User
        lbl_money.Text = bank
        'basic info
        btnHit.Enabled = False
        btnStay.Enabled = False
        tmr_bank.Enabled = True
    End Sub

    'not allow decimal in bet
    Private Sub txt_bet_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles txt_bet.KeyPress
        If (Microsoft.VisualBasic.Asc(e.KeyChar) < 48) _
              Or (Microsoft.VisualBasic.Asc(e.KeyChar) > 57) Then
            e.Handled = True
        End If
        If (Microsoft.VisualBasic.Asc(e.KeyChar) = 8) Then
            e.Handled = False
        End If
    End Sub

    Private Sub btnDeal_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDeal.Click
        'Bet amount
        If Val(txt_bet.Text) = 0 Then
            MsgBox("Please place a bet")
        ElseIf Val(txt_bet.Text) > Val(lbl_money.Text) Then
            MsgBox("Please bet lower")
            'generating first hand
        ElseIf Val(txt_bet.Text) > 0 Then
            lblPlayer.Text = Math.Ceiling(Rnd() * 20) + 1
            lblDealer.Text = Math.Ceiling(Rnd() * 20) + 1

            'buttons 
            btnDeal.Enabled = False
            btnHit.Enabled = True
            btnStay.Enabled = True

            'Deal
            If lblPlayer.Text = "21" Then
                If lblDealer.Text = 21 Then
                    MsgBox("Draw")
                Else MsgBox("Player Wins!")
                    'bet
                    lbl_money.Text = Val(lbl_money.Text) + (Val(txt_bet.Text) + Val(txt_bet.Text) / 2)
                End If
                'reset
                lblDealer.Text = ""
                lblPlayer.Text = ""
                btnDeal.Enabled = True
                btnHit.Enabled = False
                btnStay.Enabled = False

            ElseIf Val(lblDealer.Text) = Val(lblPlayer.Text) Then
                lblPlayer.Text = Math.Ceiling(Rnd() * 20)

                'Natural win/lose
            ElseIf lblDealer.Text = "21" Then
                MsgBox("Dealer Wins!")
                'bet
                lbl_money.Text = Val(lbl_money.Text) - Val(txt_bet.Text)
                'reset
                lblPlayer.Text = ""
                lblDealer.Text = ""
                btnDeal.Enabled = True
                btnHit.Enabled = False
                btnStay.Enabled = False
            End If
        End If
    End Sub

    Private Sub btnHit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnHit.Click
        If Val(lblPlayer.Text) < 11 Then
            lblPlayer.Text = Val(lblPlayer.Text) + Math.Ceiling(Rnd() * 11)
        Else lblPlayer.Text = Val(lblPlayer.Text) + Math.Ceiling(Rnd() * 10)
        End If

        If Val(lblDealer.Text) < 17 Then
            If Val(lblDealer.Text) > 10 Then
                lblDealer.Text = Val(lblDealer.Text) + Math.Ceiling(Rnd() * 10)
            Else lblDealer.Text = Val(lblDealer.Text) + Math.Ceiling(Rnd() * 11)
            End If

        End If

        If Val(lblPlayer.Text) < 21 Then
            If Val(lblDealer.Text) = 21 Then
                MsgBox("Dealer Wins!")
                'bet
                lbl_money.Text = Val(lbl_money.Text) - Val(txt_bet.Text)
                'reset
                lblPlayer.Text = ""
                lblDealer.Text = ""
                btnDeal.Enabled = True
                btnHit.Enabled = False
                btnStay.Enabled = False
            ElseIf Val(lblDealer.Text) > 21 Then
                MsgBox("Dealer Busts!
Player Wins!")
                'bet
                lbl_money.Text = Val(lbl_money.Text) + Val(txt_bet.Text)
                'reset
                lblPlayer.Text = ""
                lblDealer.Text = ""
                btnDeal.Enabled = True
                btnHit.Enabled = False
                btnStay.Enabled = False
            End If
        ElseIf Val(lblPlayer.Text) > 21 Then
            If Val(lblDealer.Text) <= 21 Then
                MsgBox("Dealer Wins!")
                'bet
                lbl_money.Text = Val(lbl_money.Text) - Val(txt_bet.Text)
            Else MsgBox("Both Bust! 
Draw!")
            End If
            'reset
            lblPlayer.Text = ""
            lblDealer.Text = ""
            btnDeal.Enabled = True
            btnHit.Enabled = False
            btnStay.Enabled = False
            '
        ElseIf Val(lblPlayer.Text) = 21 Then
            If Val(lblDealer.Text) = 21 Then
                MsgBox("Draw!")
            Else MsgBox("Player Wins!")
                'bet
                lbl_money.Text = Val(lbl_money.Text) + Val(txt_bet.Text)
            End If
            'reset
            lblPlayer.Text = ""
            lblDealer.Text = ""
            btnDeal.Enabled = True
            btnHit.Enabled = False
            btnStay.Enabled = False
        End If
    End Sub

    Private Sub btnStay_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnStay.Click
        If Val(lblDealer.Text) < 17 Then
            If Val(lblDealer.Text) < 11 Then
                lblDealer.Text = Val(lblDealer.Text) + Math.Ceiling(Rnd() * 11)
            Else lblDealer.Text = Val(lblDealer.Text) + Math.Ceiling(Rnd() * 10)
            End If
        End If

        If Val(lblPlayer.Text) > Val(lblDealer.Text) Then
            MsgBox("Player Wins!")
            'bet
            lbl_money.Text = Val(lbl_money.Text) + Val(txt_bet.Text)
        ElseIf Val(lblPlayer.Text) = Val(lblDealer.Text) Then
            MsgBox("Draw!")
        ElseIf Val(lblPlayer.Text) < Val(lblDealer.Text) And Val(lblDealer.Text) <= 21 Then
            MsgBox("Dealer Wins!")
            'bet
            lbl_money.Text = Val(lbl_money.Text) - Val(txt_bet.Text)
        Else MsgBox("The Dealer Busts!
Player Wins!")
            'bet
            lbl_money.Text = Val(lbl_money.Text) + Val(txt_bet.Text)
        End If
        'reset
        lblPlayer.Text = ""
        lblDealer.Text = ""
        btnDeal.Enabled = True
        btnHit.Enabled = False
        btnStay.Enabled = False
    End Sub

    Private Sub btn_help_Click(sender As Object, e As EventArgs) Handles btn_help.Click
        MsgBox("~~~~~~~~~ BLACKJACK/21 ~~~~~~~~~

Your aim is to get as close to 21 as possible
(before the Dealer does)
Place your bet, and see if you win!
-------------------------------------------
Hit = Get another random card
Stand = Keep your hand

If you get over 21, or the Dealer is closer to 21, you lose
If you get closer to, or exactly 21 (or the Dealer busts), you WIN
-------------------------------------------
Ace = 1 or 11 (depending on your hand)
2-9 = value of card
Face cards (Jack, Queen, King) = 10")
    End Sub

    Private Sub btn_back_Click(sender As Object, e As EventArgs) Handles btn_back.Click
        'changing bank integer on other forms
        bank = Val(lbl_money.Text)
        Form3.lbl_money.Text = bank
        'closing/opening forms
        Form3.Show()
        Me.Close()
    End Sub

    Private Sub tmr_bank_Tick(sender As Object, e As EventArgs) Handles tmr_bank.Tick
        If Val(lbl_money.Text) <= 0 Then
            tmr_bank.Enabled = False
            'changing bank integer on other forms
            bank = Val(lbl_money.Text)
            Form3.lbl_money.Text = bank
            'closing form
            Form3.Show()
            Me.Close()
        End If
    End Sub
End Class
