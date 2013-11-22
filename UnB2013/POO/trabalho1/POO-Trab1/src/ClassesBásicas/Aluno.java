package ClassesBásicas;

public class Aluno {
	private String name, adress, phone;
	private int age;
	private int numberCursos;
	
	//---------------------------------------------------
	//-------------Construtores--------------------------
	//---------------------------------------------------
	public Aluno(String newNm, String newAd, String newPh, int newAg){
		setName(newNm);
		setAdress(newAd);
		setPhone(newPh);
		setAge(newAg);
	}

	public Aluno(String newNm){
		setName(newNm);
		setAdress("não informado");
		setPhone("não informado");
		setAge(-1);
		numberCursos = 0;
	}
	//---------------------------------------------------
	//-------------Getters-------------------------------
	//---------------------------------------------------
	public String getName(){
		return name;
	}
	
	public String getAdress(){
		return adress;
	}
	
	public String getPhone(){
		return phone;
	}
	
	public int getAge(){
		return age;
	}
	
	public int getNCurses(){
		return numberCursos;
	}
	//---------------------------------------------------
	//-------------Setters-------------------------------
	//---------------------------------------------------
	public void setName(String newName){
		name = newName;
	}
	
	public void setAdress(String newAd){
		adress = newAd;
	}
	
	public void setPhone(String newPh){
		phone = newPh;
	}
	
	public void setAge(int newAg){
		age = newAg;
	}

	public void upNCursos(){
		numberCursos += 1;
	}

	public void downNCursos(){
		numberCursos -= 1;
	}

}//fim da classe Aluno
