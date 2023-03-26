import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class FuncionarioDAO extends DataAccessObject<Funcionario> {

    private Connection conexao;

    public FuncionarioDAO(){
        this.conexao = Conexao.getConnection();
    }
    @Override
    public List<Funcionario> findAll() {
        List<Funcionario> funcionarios = new ArrayList<>();

        try{
            Statement statement = this.conexao.createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM funcionarios");

            while(rs.next()){
                String cpf = rs.getString("cpf");
                String nome = rs.getString("nome");
                String sobrenome = rs.getString("sobrenome");
                String telefone = rs.getString("telefone");
                String email = rs.getString("email");
                boolean tat = rs.getBoolean("tat");
                boolean prc = rs.getBoolean("prc");

                Funcionario atual = new Funcionario(cpf, nome, sobrenome, telefone, email, tat, prc);
                funcionarios.add(atual);
            }


        } catch (SQLException e) {
            System.err.println("Erro ao obter lista de funcionarios: " + e.getMessage());
        }

        return funcionarios;
    }

    @Override
    public Funcionario insert(Funcionario funcionario) {

        Funcionario funcionarioInserido = null;
        String insertQuerry = "INSERT INTO funcionarios (cpf, nome, sobrenome, telefone, email, tat, prc, createdAt, updatedAt, contaCpf) " +
                              "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        try{

            //Variaveis data
            java.sql.Date sqlCreated = new java.sql.Date(funcionario.getCreatedAt().getTime());
            java.sql.Date sqlUpdated = new java.sql.Date(funcionario.getUpdatedAt().getTime());

            //Parametros do insert into
            PreparedStatement ps = this.conexao.prepareStatement(insertQuerry, PreparedStatement.RETURN_GENERATED_KEYS);
            ps.setString(1, funcionario.getCpf());
            ps.setString(2, funcionario.getNome());
            ps.setString(3, funcionario.getSobrenome());
            ps.setString(4, funcionario.getTelefone());
            ps.setString(5, funcionario.getEmail());
            ps.setBoolean(6, funcionario.getTat());
            ps.setBoolean(7, funcionario.getPrc());
            ps.setDate(8, sqlCreated);
            ps.setDate(9, sqlUpdated);
            ps.setString(10, funcionario.getCpf());


        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return funcionarioInserido;
    }
}
