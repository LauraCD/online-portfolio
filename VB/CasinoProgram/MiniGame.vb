Public Class Form6
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
    Private Sub Form6_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Size = New Size(900, 860)
        Me.CenterToParent()
        MaximizeBox = False
        Form1.Hide()
        MsgBox("Before we start, let's see how much money you'll start off with!")
        MsgBox("Press STOP, and see how lucky you are, " + User + "!")

    End Sub
    'SLOTS game
    Dim a As Integer

    Private Sub tmr_spin_Tick(sender As Object, e As EventArgs) Handles tmr_spin.Tick

        a = Math.Ceiling(Rnd() * 3)

        Select Case a
            Case 1
                PictureBox1.Image = Image.FromFile("SlotsImage1")
            Case 2
                PictureBox1.Image = Image.FromFile("SlotsImage2")
            Case 3
                PictureBox1.Image = Image.FromFile("SlotsImage3")
        End Select

    End Sub

    Private Sub btn_spin_Click(sender As Object, e As EventArgs) Handles btn_spin.Click
        tmr_spin.Enabled = False
        a = Math.Ceiling(Rnd() * 3)

        Select Case a
            Case 1
                PictureBox1.Image = Image.FromFile("SlotsImage1")
                MsgBox("You win $1000")
                lbl_money.Text = 1000
            Case 2
                PictureBox1.Image = Image.FromFile("SlotsImage2")
                MsgBox("You win $2000")
                lbl_money.Text = 2000
            Case 3
                PictureBox1.Image = Image.FromFile("SlotsImage3")
                MsgBox("You win $3000")
                lbl_money.Text = 3000
        End Select
        'changing bank integer on other forms
        Dim bank As Integer
        bank = Val(lbl_money.Text)
        Form3.lbl_money.Text = bank
        'closing/opening forms
        Form3.Show()
        Me.Close()
    End Sub
End Class
