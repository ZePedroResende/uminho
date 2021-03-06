import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.stream.Collectors;

class Playlist{


    private List <Faixa> faixas;

    public Playlist(){
        this.faixas=new ArrayList<Faixa>();
    }

    public Playlist (List<Faixa> faixas){
        this.faixas=new ArrayList<Faixa>();
        for(Faixa f:faixas)
            this.faixas.add(f.clone());
    }

    public Playlist(Playlist p){
        this(p.getFaixas());
    }

    public List<Faixa> getFaixas(){
        ArrayList<Faixa> aux=new ArrayList<Faixa>();
        for(Faixa f:this.faixas)
            aux.add(f.clone());
        return aux;
    }

    public List <Faixa> getFaixasF () {
        return faixas.stream().map(Faixa::clone).collect(Collectors.toList());
    }

    public List<Faixa> getFaixas2(){
        ArrayList<Faixa> aux=new ArrayList<Faixa>(this.faixas.size());
        Iterator<Faixa> it=this.faixas.iterator();
        while(it.hasNext()){
            Faixa f;
            f=it.next();
            aux.add(f.clone());
        }
        return aux;
    }

    private void setFaixas(List<Faixa> faixas){
        this.faixas.clear();
        for(Faixa f: faixas)
            this.faixas.add(f.clone());
    }

    public void setFaixasF (List <Faixa> faixas) {
        this.faixas = faixas.stream().map(Faixa::clone).collect(Collectors.toList());
    }




    public int numFaixas(){
        return this.faixas.size();
    }

    public void addFaixa(Faixa f){
        this.faixas.add(f);
    }

    public void removeFaixa(Faixa m){
        this.faixas.remove(m);
    }


    public void adicionar(List<Faixa> faixas){
        Iterator<Faixa> it=faixas.iterator();
        while(it.hasNext()){
            Faixa f=it.next();
            if(!this.faixas.contains(f))
                this.faixas.add(f.clone());
        }
    }

    public void adicionarF(List<Faixa> faixas){
        faixas.forEach(f->{this.faixas.add(f.clone());});
    }

    public int classificacaoSuperior(Faixa f){
        Iterator<Faixa> it=this.faixas.iterator();
        int r=0;
        while(it.hasNext()){
            Faixa g=it.next();
            if(g.getClassificacao() > f.getClassificacao()) r++;
        }
        return r;
    }

    public int classificacaoSuperiorF(Faixa f){
        return (int) this.faixas.stream()
            .filter(t->t.getClassificacao() > f.getClassificacao())
            .count();
    }

    public boolean duracaoSuperior(double d){
        Iterator<Faixa> it=this.faixas.iterator();
        boolean flag=false;
        while(it.hasNext() && !flag){
            Faixa g=it.next();
            if(g.getDuracao() > d) flag=true;
        }
        return flag;
    }

    public boolean duracaoSuperiorF(double d){
        return this.faixas.stream().anyMatch(f->f.getDuracao() > d);
    }


    public double duracaoTotalF(){
        return faixas.stream().mapToDouble(Faixa::getDuracao).sum();
    }

    public void removeFaixas(String autor){
        Interator <Faixa> it = faixas.iteratir();
        while(it.hasNext()){
            Faixa f =it.next();
            if(f.getAutor().equals(autor)){
                it.remove();
            }
        }
    }

    public void removeFaixasF (String autor){
        faixas.removeIt (f-> f.getAutor().equals(autor));
        faixas.removeIt (f-> f.getAutor().equals(autor));
    }
}
