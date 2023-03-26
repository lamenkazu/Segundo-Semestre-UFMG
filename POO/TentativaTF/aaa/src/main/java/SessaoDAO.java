import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class SessaoDAO extends DataAccessObject<Sessao>{

    private Connection conexao;

    public SessaoDAO(){
        this.conexao = Conexao.getConnection();
    }
    @Override
    public List<Sessao> findAll() {
        List<Sessao> sessoes = new ArrayList<>();

        try{
            Statement st = this.conexao.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM agendamentos");

            while(rs.next()){

                int id = rs.getInt("id");
                Date data = rs.getDate("data");
                Double valor = rs.getDouble("valor");
                boolean tat = rs.getBoolean("tat");
                boolean prc = rs.getBoolean("prc");
                String funcionarioCpf = rs.getString("funcionarioCpf");
                String clienteCpf = rs.getString("clienteCpf");

                Sessao atual = new Sessao(id, data, valor, tat, prc, funcionarioCpf, clienteCpf);
                sessoes.add(atual);
            }

        } catch (SQLException e) {
            System.err.println("Erro ao obter lista de sessoes: " + e.getMessage());
        }


        return sessoes;
    }

    @Override
    public Sessao insert(Sessao obj) {
        return null;
    }
}
