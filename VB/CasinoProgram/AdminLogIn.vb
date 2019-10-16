Public Class Form2
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'opening form to size and location wanted
        Me.CenterToParent()
        Me.Size = New Size(400, 300)
        ControlBox = True
        MaximizeBox = False
        MinimizeBox = True
    End Sub

    Private Sub btn_exit_Click(sender As Object, e As EventArgs) Handles btn_exit.Click
        'Closing the form if not needed
        Me.Close()

    End Sub

    Private Sub btn_login_Click(sender As Object, e As EventArgs) Handles btn_login.Click
        'Admin username and password
        If txt_user.Text = "CRAdmin" And txt_pw.Text = "elayoRonisaC" Then
            Form7.Show()
            Me.Close()
        ElseIf MsgBox("Username and/or password is incorrect.") Then
            txt_pw.Text = ""
            txt_user.Text = ""
        End If
    End Sub
End Class
