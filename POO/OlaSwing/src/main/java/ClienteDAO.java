import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ClienteDAO extends DataAccessObject<Cliente>{

    private Connection conexao;

    public ClienteDAO() { this.conexao = Conexao.getConnection();}



    public List<Cliente> findAll(){
        List<Cliente> clientes = new ArrayList<>();

        try{

            Statement statement = this.conexao.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT * FROM clientes");


            while(resultSet.next()){
                String caughtCpf = resultSet.getString("cpf");
                String caughtNome = resultSet.getString("nome");
                String caughtTelefone = resultSet.getString("telefone");
                String caughtEmail = resultSet.getString("email");

                Cliente atual = new Cliente(caughtCpf, caughtNome, caughtTelefone, caughtEmail);
                //JOptionPane.showMessageDialog(null, atual.toString());
                clientes.add(atual);
            }


        } catch (SQLException e) {
            System.err.println("Erro ao obter lista de clientes: " + e.getMessage());
        }


        return clientes;
    }

    public Cliente findById(String cpf){

        Cliente cliente = null;

        try{
            Statement statement = this.conexao.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT * FROM clientes WHERE cpf = " + cpf);

            if(resultSet.next()){
                String caughtNome = resultSet.getString("nome");
                String caughtTelefone = resultSet.getString(("telefone"));
                String caughtEmail = resultSet.getString("email");

                cliente = new Cliente(cpf, caughtNome, caughtTelefone, caughtEmail);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return cliente;
    }

    public Cliente insert(Cliente cliente){
        Cliente clienteInserido = null;

        String insertQuery = "INSERT INTO clientes (cpf, nome, telefone, email, createdAt, updatedAt) VALUES (?, ?, ?, ?, ?, ?)";

        try {
            //Variaveis data
            java.sql.Date sqlCreated = new java.sql.Date(cliente.getCreatedAt().getTime());
            java.sql.Date sqlUpdated = new java.sql.Date(cliente.getUpdatedAt().getTime());

            //Define Parametros do Insert Into
            PreparedStatement ps = this.conexao.prepareStatement(insertQuery, PreparedStatement.RETURN_GENERATED_KEYS);
            ps.setString(1, cliente.getCpf());
            ps.setString(2, cliente.getNome());
            ps.setString(3, cliente.getTelefone());
            ps.setString(4, cliente.getEmail());
            ps.setDate(5, sqlCreated);
            ps.setDate(6, sqlUpdated);


        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return clienteInserido;

    }


    public boolean update(Cliente cliente) {

        boolean resposta = false;
        String updateQuery = "UPDATE clientes SET cpf = ?, nome = ?, telefone = ?, email = ?, updatedAt = ?";

        try{
            cliente.setUpdatedAt();
            java.sql.Date sqlUpdated = new java.sql.Date(cliente.getUpdatedAt().getTime());

            PreparedStatement ps = this.conexao.prepareStatement(updateQuery);
            ps.setString(1, cliente.getCpf());
            ps.setString(2, cliente.getNome());
            ps.setString(3, cliente.getTelefone());
            ps.setString(4, cliente.getEmail());
            ps.setDate(5, sqlUpdated);

            resposta = ps.execute();


        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return resposta;
    }


    public boolean delete(Cliente cliente) {

        boolean resposta = false;

        String deleteQuery = "DELETE FROM clientes WHERE cpf = ?";

        try{
            PreparedStatement ps = this.conexao.prepareStatement((deleteQuery));
            ps.setString(1, cliente.getCpf());

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return resposta;
    }
}
