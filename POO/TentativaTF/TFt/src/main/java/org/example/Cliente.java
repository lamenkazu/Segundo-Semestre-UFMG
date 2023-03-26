import java.util.Date;

public class Cliente {

    private String cpf;

    private String nome ;

    private String telefone;

    private String email;

    private Date createdAt;

    private Date updatedAt;

    public Cliente (String cpf, String nome, String telefone, String email){
        this.cpf = cpf;
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.createdAt = new Date();
        this.updatedAt = new Date();
    }

    public String toString(){
        return "Cliente{" +
                "cpf: "+ cpf +
                "nome: "+ nome +
                "telefone: "+ telefone +
                "email: "+ email +
                "createdAt: "+ createdAt +
                "updatedAt: "+ updatedAt +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;

        if(obj == null || getClass() != obj.getClass())
            return false;

        Cliente cliente = (Cliente) obj;

        return this.getCpf().equals(cliente.getCpf()) &&
                    this.getNome().equals(cliente.getNome()) &&
                    this.getTelefone().equals(cliente.getTelefone()) &&
                    this.getEmail().equals(cliente.getEmail());
    }

    public String getCpf() {
        return cpf;
    }

    public String getNome() {
        return nome;
    }

    public Date getCreatedAt() {
        return createdAt;
    }

    public Date getUpdatedAt() {
        return updatedAt;
    }

    public void setUpdatedAt() {
        this.updatedAt = new Date();
    }

    public String getEmail() {
        return email;
    }

    public String getTelefone() {
        return telefone;
    }
}
