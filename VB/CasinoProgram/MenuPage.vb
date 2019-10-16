'Form 3 is the main game page
Imports System.Data.OleDb

Public Class Form3
    'For time save
    Dim provider As String
    Dim dataFile As String
    Dim connString As String
    Dim myConnection As OleDbConnection = New OleDbConnection

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

    Private Sub Form3_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Page size and location on screen
        Size = New Size(1100, 860)
        Me.CenterToParent()
        'pictureboxes
        pic_slots.Image = Image.FromFile("L:\.LAURA\2019\Casino_Program1\icons\Logos\logoSlots.jpg")
        pic_BlackJack.Image = Image.FromFile("L:\.LAURA\2019\Casino_Program1\icons\Logos\logo21.jpg")
        'timers
        tmr_bank.Enabled = True
        tmr_time.Enabled = True
        'maximise
        MaximizeBox = False
        'Bank variable
        Dim bank As Integer
        'Labels
        lbl_user.Text = User
        bank = lbl_money.Text

    End Sub

    Private Sub btn_exit_Click(sender As Object, e As EventArgs) Handles btn_exit.Click
        'exit
        MsgBox("Thanks for playing! Come back soon.")
        lbl_bankrupt.Text = "No"
        'saving time
        provider = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source="
        dataFile = "L:\.LAURA\2019\Casino_Program1\Time_Save\CasinoRoyale.accdb"
        connString = provider & dataFile
        myConnection.ConnectionString = connString
        myConnection.Open()
        Dim str As String
        str = "Insert into CRTime ([Hour],[Minute],[Second],[Bankrupt?]) Values (?, ?, ?, ?)"
        Dim cmd As OleDbCommand = New OleDbCommand(str, myConnection)
        cmd.Parameters.Add(New OleDbParameter("Hour", CType(lbl_hour.Text, Integer)))
        cmd.Parameters.Add(New OleDbParameter("Minute", CType(lbl_min.Text, Integer)))
        cmd.Parameters.Add(New OleDbParameter("Second", CType(lbl_sec.Text, Integer)))
        cmd.Parameters.Add(New OleDbParameter("Bankrupt?", CType(lbl_bankrupt.Text, String)))

        Try
            cmd.ExecuteNonQuery()
            cmd.Dispose()
            myConnection.Close()
        Catch ex As Exception
            MsgBox(ex.Message)
        End Try

        'closing
        Form1.Show()
        Me.Close()
    End Sub

    Private Sub btn_slots_Click(sender As Object, e As EventArgs) Handles btn_slots.Click
        Form4.Show()
        Me.Hide()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form5.Show()
        Me.Hide()
    End Sub

    Private Sub tmr_bank_Tick(sender As Object, e As EventArgs) Handles tmr_bank.Tick
        'bankrupt
        If Val(lbl_money.Text) <= 0 Then
            tmr_bank.Enabled = False
            lbl_bankrupt.Text = "Yes"
            MsgBox("You went bankrupt and the Casino have KICKED YOU OUT!
Bad luck :(")
            'saving time
            provider = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source="
            dataFile = "L:\.LAURA\2019\Casino_Program1\Time_Save\CasinoRoyale.accdb"
            connString = provider & dataFile
            myConnection.ConnectionString = connString
            myConnection.Open()
            Dim str As String
            str = "Insert into CRTime ([Hour],[Minute],[Second],[Bankrupt?]) Values (?, ?, ?, ?)"
            Dim cmd As OleDbCommand = New OleDbCommand(str, myConnection)
            cmd.Parameters.Add(New OleDbParameter("Hour", CType(lbl_hour.Text, Integer)))
            cmd.Parameters.Add(New OleDbParameter("Minute", CType(lbl_min.Text, Integer)))
            cmd.Parameters.Add(New OleDbParameter("Second", CType(lbl_sec.Text, Integer)))
            cmd.Parameters.Add(New OleDbParameter("Bankrupt?", CType(lbl_bankrupt.Text, String)))

            Try
                cmd.ExecuteNonQuery()
                cmd.Dispose()
                myConnection.Close()
            Catch ex As Exception
                MsgBox(ex.Message)
            End Try

            'closing pages
            Form1.Show()
            Me.Close()
        End If
    End Sub

    Private Sub tmr_time_Tick(sender As Object, e As EventArgs) Handles tmr_time.Tick
        'seconds on game
        lbl_sec.Text += 1
        'minutes
        If Val(lbl_sec.Text) = 60 Then
            lbl_sec.Text = 0
            lbl_min.Text += 1
        End If
        'hours
        If Val(lbl_min.Text) = 60 Then
            lbl_min.Text = 0
            lbl_hour.Text += 1
        End If
    End Sub

End Class
