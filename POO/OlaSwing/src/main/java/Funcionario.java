import java.util.Date;

public class Funcionario {

    private String cpf;

    private String nome;

    private String sobrenome;

    private String telefone;

    private String email;

    private boolean tat = false;

    private boolean prc = false;

    private Date createdAt;

    private Date updatedAt;

    private String contaCpf;

    public Funcionario(String cpf, String nome,String sobrenome,  String telefone, String email, boolean tat, boolean prc){
        this.cpf = cpf;
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.telefone = telefone;
        this.email = email;
        this.tat = tat;
        this.prc = prc;
        this.createdAt = new Date();
        this.updatedAt = new Date();

    }

    public String toString(){
        return "Funcionario{" +
                "cpf: "+ cpf +
                "nome: "+ nome +
                "sobenome: "+ sobrenome +
                "telefone: "+ telefone +
                "email: "+ email +
                "tatoo: "+ tat +
                "piercing: "+ prc +
                "createdAt: "+ createdAt +
                "updatedAt: "+ updatedAt +
                '}';
    }

    public boolean equals(Object obj) {
        if(this == obj)
            return true;

        if(obj == null || getClass() != obj.getClass())
            return false;

        Funcionario funcionario = (Funcionario) obj;

        return this.getCpf().equals(funcionario.getCpf()) &&
                this.getNome().equals(funcionario.getNome()) &&
                this.getSobrenome().equals(funcionario.getSobrenome()) &&
                this.getTelefone().equals(funcionario.getTelefone()) &&
                this.getEmail().equals(funcionario.getEmail());
    }

    public String getCpf() {
        return cpf;
    }

    public String getNome() {
        return nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getEmail() {
        return email;
    }

    public Date getCreatedAt() {
        return createdAt;
    }

    public Date getUpdatedAt() {
        return updatedAt;
    }

    public boolean getTat(){
        return tat;
    }

    public boolean getPrc(){
        return prc;
    }

}
