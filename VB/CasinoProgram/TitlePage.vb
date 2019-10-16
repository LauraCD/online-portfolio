Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'size and location
        Size = New Size(900, 860)
        Me.CenterToParent()
        'picture box
        pic_title.Image = Image.FromFile("CasinoTitleImage")
        'max box
        MaximizeBox = False
    End Sub

    Private Sub lbl_admin_DoubleClick(sender As Object, e As EventArgs) Handles lbl_admin.DoubleClick
        'admin log-in
        Form2.Show()
    End Sub

    Private Sub btn_exit_Click(sender As Object, e As EventArgs) Handles btn_exit.Click
        'exit program
        End
    End Sub

    Private Sub btn_play_Click(sender As Object, e As EventArgs) Handles btn_play.Click
        'username
        If txt_name.Text.Length <= 4 Then
            MsgBox("Please enter a username (at least 5 characters) and tick the checkbox")
            'making sure age appropriate
        ElseIf chk_age.Checked = True Then
            'player is verified/accepted
            Dim User As String = txt_name.Text
            MsgBox("Welcome " + User + ", get ready to play!")
            Form6.Show()
            Me.Hide()
        ElseIf MsgBox("Please tick the checkbox") Then
        End If
    End Sub
End Class
