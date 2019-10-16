Public Class Form4
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
    Private Sub Form4_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Page size and location on screen
        Size = New Size(1100, 860)
        Me.CenterToParent()
        'Getting rid of the maximise
        MaximizeBox = False
        'Username
        lbl_user.Text = User
        lbl_money.Text = bank
        'timers
        tmr_bank.Enabled = True
        'Starting game with pics
        PictureBox1.Image = Image.FromFile("SlotsImage1")
        PictureBox2.Image = Image.FromFile("SlotsImage1")
        PictureBox3.Image = Image.FromFile("SlotsImage1")
    End Sub

    'SLOTS game
    Dim m, a, b, c As Integer

    Private Sub btn_spin_Click(sender As Object, e As EventArgs) Handles btn_spin.Click
        tmr_spin.Enabled = True
        lbl_money.Text = Val(lbl_money.Text) - 100
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

    Private Sub tmr_spin_Tick(sender As Object, e As EventArgs) Handles tmr_spin.Tick
        btn_spin.Enabled = False
        m = m + 10
        If m < 230 Then

            a = Math.Ceiling(Rnd() * 6)

            b = Math.Ceiling(Rnd() * 6)

            c = Math.Ceiling(Rnd() * 6)

            Select Case a
                Case 1
                    PictureBox1.Image = Image.FromFile("SlotsImage1")
                Case 2
                    PictureBox1.Image = Image.FromFile("SlotsImage2")
                Case 3
                    PictureBox1.Image = Image.FromFile("SlotsImage3")
                Case 4
                    PictureBox1.Image = Image.FromFile("SlotsImage4")
                Case 5
                    PictureBox1.Image = Image.FromFile("SlotsImage5")
                Case 6
                    PictureBox1.Image = Image.FromFile("SlotsImage6")
            End Select

            Select Case b
               Case 1
                    PictureBox1.Image = Image.FromFile("SlotsImage1")
                Case 2
                    PictureBox1.Image = Image.FromFile("SlotsImage2")
                Case 3
                    PictureBox1.Image = Image.FromFile("SlotsImage3")
                Case 4
                    PictureBox1.Image = Image.FromFile("SlotsImage4")
                Case 5
                    PictureBox1.Image = Image.FromFile("SlotsImage5")
                Case 6
                    PictureBox1.Image = Image.FromFile("SlotsImage6")
            End Select

            Select Case c
               Case 1
                    PictureBox1.Image = Image.FromFile("SlotsImage1")
                Case 2
                    PictureBox1.Image = Image.FromFile("SlotsImage2")
                Case 3
                    PictureBox1.Image = Image.FromFile("SlotsImage3")
                Case 4
                    PictureBox1.Image = Image.FromFile("SlotsImage4")
                Case 5
                    PictureBox1.Image = Image.FromFile("SlotsImage5")
                Case 6
                    PictureBox1.Image = Image.FromFile("SlotsImage6")
            End Select

        Else
            tmr_spin.Enabled = False
            btn_spin.Enabled = True
            m = 0
            If a = b Then
                If b = c Then
                    LblMsg.Text = “JACKPOT!!! You won $10,000!"
                    lbl_money.Text = Val(lbl_money.Text) + 10000
                Else
                    LblMsg.Text = "AMAZING! You won $200!"
                    lbl_money.Text = Val(lbl_money.Text) + 200
                End If
            ElseIf a = c Then
                LblMsg.Text = "NICE! You won $150!"
                lbl_money.Text = Val(lbl_money.Text) + 150
            ElseIf b = c Then
                LblMsg.Text = "AMAZING! You won $200!"
                lbl_money.Text = Val(lbl_money.Text) + 200
            Else
                LblMsg.Text = “Bad luck :(  Try again?”

            End If
        End If
    End Sub

    Private Sub btn_help_Click(sender As Object, e As EventArgs) Handles btn_help.Click
        MsgBox("      ~~~~~~~~~ SLOTS ~~~~~~~~~

Press the 'SPIN' button to play!
Each play costs $100
------------------------
[-][-][-] = LOSE (no money won)
[X][-][X] = WIN $150
[X][X][-] or [-][X][X] = WIN $200
[X][X][X] = JACKPOT $10,000
------------------------
Good luck! :)")
    End Sub

    Private Sub btn_back_Click(sender As Object, e As EventArgs) Handles btn_back.Click
        'changing bank integer on other forms
        bank = Val(lbl_money.Text)
        Form3.lbl_money.Text = bank
        'closing/opening forms
        Form3.Show()
        Me.Close()
    End Sub
End Class
