import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conexao {

    private Connection databaseConnection;

    private static Conexao conexao = null;

    /*
    //Dados para se conectar ao banco de dados
    private static final String DB_URI =
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

     */


    public static Connection getConnection(){
        String DB_URI = "jdbc:mysql://localhost:3306/studiobodyart";
        String DB_USER = "root";
        String DB_PASSWORD = "";

        Connection conn = null;

        try{
            Class.forName("com.mysql.cj.jdbc.Driver");

            conn = DriverManager.getConnection(DB_URI, DB_USER, DB_PASSWORD);
        } catch (SQLException e) {
            System.err.println("Conexao nao realizada: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.err.println("Driver nao carregado: " + e.getMessage());
        }

        return conn;
    }



}
