import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class AbasFuncionario {
    private JTabbedPane menuPrincipal;
    private JPanel painelFuncionario;
    private JTabbedPane menuFuncionarios;
    private JTabbedPane menuClientes;
    private JTabbedPane menuSessoes;
    private JTable tabelaClientes;

    public JFrame abas() {

        JFrame func = new JFrame("Funcionario");
        func.setContentPane(new AbasFuncionario().painelFuncionario);
        func.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        func.pack();
        func.setVisible(true);

        return func;

    }
    public AbasFuncionario(){

        ClienteDAO clientes = new ClienteDAO();

        String[] colListaClientes = {"CPF", "Nome", "Telefone", "Email", "Criado em", "Atualizado em"};
        DefaultTableModel modelListaClientes = new DefaultTableModel(colListaClientes, 5);
        this.tabelaClientes = new JTable(modelListaClientes);

    }

    public static void main(String[] args) {
        JFrame func = new JFrame("Funcionario");
        func.setContentPane(new AbasFuncionario().painelFuncionario);
        func.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        func.pack();
        func.setVisible(true);
    }


}

