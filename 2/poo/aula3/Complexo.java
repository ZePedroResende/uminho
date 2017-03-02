
/**
 * Write a description of class Complexo here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Complexo
{
    private double a;
    private double bi;
    public Complexo(){
        a=bi=0;
    }
    
    public Complexo(Complexo o){
        a = o.a;
        bi = o.bi;
    }
    
    public Complexo(double a, double bi){
        this.a = a;
        this.bi = bi;
    }
    /**
     * Constructor for objects of class Complexo
     */
   public double getA(){
    return a;
    }
    
   public double getBi(){
       return bi;
   }
   
   public void SetA(double d){
       a=d;
    }
    
  public void SetBi(double d){
      bi = d;
  }
  
  
  public boolean equals(Complexo c){
      /*if(this == c)
        return true;
        
      if(c.a != a)
        return false;
      
      if (c.bi != bi)
        return false;
      
        return true;*/
        
        return (this == c && c.a  == a && c.bi == bi);  
  }
    
    
  public Complexo clone(){
        return new Complexo(this);
  }
  
  public String toString(){
      return new String(a+"+"+bi);
  }
  
  public Complexo conjufado(){
      return new Complexo(a,-bi);
  }
  
  public Complexo soma(Complexo c){
      return new Complexo(a+c.a, bi+c.bi);
  }
  
  public Complexo produto(Complexo c){
      return new Complexo((a*c.a-bi*c.bi),(bi*c.a + a *c.bi));
  }
  
  public Complexo reciproco(){
      double na = a/(Math.pow(a,2)+Math.pow(bi,2));
      double nbi = bi/(Math.pow(a,2)+Math.pow(bi,2));
      return new Complexo(na,nbi);
  }
  
  
}
