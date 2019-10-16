Imports System.Data.OleDb
Public Class Form7
    Private Sub Form7_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'loading time data
        Try
            Dim thisconnection As System.Data.OleDb.OleDbConnection
            Dim dataset As System.Data.DataSet
            Dim mycommand As System.Data.OleDb.OleDbDataAdapter
            Dim path As String = "DataFileName(.accdb)"

            thisconnection = New System.Data.OleDb.OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source =" + path + ";")
            mycommand = New System.Data.OleDb.OleDbDataAdapter("select * from [CRTime] ORDER BY ID", thisconnection)

            dataset = New System.Data.DataSet
            mycommand.Fill(dataset)
            DataGridView1.DataSource = dataset.Tables(0)
            thisconnection.Close()
        Catch ex As Exception
            MsgBox(ex.Message.ToString)

        End Try
    End Sub
    Private Sub btn_exit_Click(sender As Object, e As EventArgs) Handles btn_exit.Click
        'closing
        Form1.Show()
        Me.Close()
    End Sub
End Class
