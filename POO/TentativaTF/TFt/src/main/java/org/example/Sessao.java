import java.util.Date;

public class Sessao {

    private Integer id;

    private Date data;

    private Double valor;

    private Date createdAt;

    private Date updatedAt;

    private boolean tat;

    private boolean prc;

    private String funcionarioCpf;

    private String clienteCpf;

    public Sessao(int id, Date data, Double valor,
                  boolean tat, boolean prc,
                  String funcionarioCpf, String clienteCpf){

        this.id = id;
        this.data = data;
        this.valor = valor;
        this.createdAt = new Date();
        this.updatedAt = new Date();
        this.tat = tat;
        this.prc = prc;
        this.funcionarioCpf = funcionarioCpf;
        this.clienteCpf = clienteCpf;

    }

    public String toString(){
        return "Sessao{" +
                "id: "+ id +
                "data: "+ data +
                "valor: "+ valor +
                "funcionarioCpf: "+ funcionarioCpf +
                "clienteCpf: "+ clienteCpf +
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

        Sessao sessao = (Sessao) obj;

        return this.getId().equals(sessao.getId()) &&
                this.getData().equals(sessao.getData()) &&
                this.getFuncionarioCpf().equals(sessao.getFuncionarioCpf()) &&
                this.getClienteCpf().equals(sessao.getClienteCpf()) &&
                this.getValor().equals(sessao.getValor());
    }

    public Integer getId() {
        return id;
    }

    public Date getData() {
        return data;
    }

    public String getFuncionarioCpf() {
        return funcionarioCpf;
    }

    public String getClienteCpf() {
        return clienteCpf;
    }

    public Double getValor() {
        return valor;
    }
}
