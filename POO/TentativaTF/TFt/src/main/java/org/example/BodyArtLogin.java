import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BodyArtLogin {
    private JTabbedPane abasLogin;
    private JPanel painelLogin;
    private JButton entrarComoGerenteButton;
    private JButton entrarComoFuncionarioButton;
    private JTextField userGer;
    private JPasswordField senhaGer;
    private JTextField userFunc;
    private JPasswordField senhaFunc;
    private JButton logarGerButton;
    private JButton logarFuncButton;

    public JFrame abas(){

        JFrame login = new JFrame("Login");
        login.setContentPane(new BodyArtLogin().painelLogin);
        login.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        login.pack();
        login.setVisible(true);


        return login;
    }

    public BodyArtLogin(){
        abasLogin.setEnabledAt(1, false);
        abasLogin.setEnabledAt(2, false);

        //Logar Funcionario
        ActionListener logarFuncionario = new ActionListener(){
            public void actionPerformed(ActionEvent e){
                abasLogin.setEnabledAt(1, true);
                abasLogin.setSelectedIndex(1);

                ActionListener logF = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {

                        painelLogin.setVisible(false);

                        System.out.println("Entroooo");

                        JFrame abasFuncionario = new AbasFuncionario().abas();




                    }
                };
                logarFuncButton.addActionListener(logF);

            }
        };
        //Logar Gerente
        ActionListener logarGerente = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                abasLogin.setSelectedIndex(2);

                ActionListener logG = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {



                    }
                };
                logarGerButton.addActionListener(logG);
            }
        };

        this.entrarComoGerenteButton.addActionListener(logarGerente);
        this.entrarComoFuncionarioButton.addActionListener(logarFuncionario);
    }

    public static void main(String[] args) {
        new BodyArtLogin().abas();

    }
}
