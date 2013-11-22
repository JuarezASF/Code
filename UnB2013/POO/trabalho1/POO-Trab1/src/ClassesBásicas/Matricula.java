package ClassesBásicas;

public class Matricula {
	private Curso curse;
	private Aluno student;
	private  int number;
	private static int current;
	//current indica o número do próximo a ser matriculado
	
	//---------------------------------------------------
	//-------------Construtores--------------------------
	//---------------------------------------------------
	private void  setMatricula(Curso newCrs, Aluno newStd){
		setAluno(newStd);
		setCurso(newCrs);
	}

	public Matricula(Curso newCrs, Aluno newStd){
		setMatricula(newCrs, newStd);
		number = -1;
		//matrículas instanciada localmente não tem número!
	}
	
	public void makeMember(){
		number = current++;
		//elas somente ganham o número quando feitas membras!
		}
	
	//---------------------------------------------------
	//-------------Getters-------------------------------
	//---------------------------------------------------
	public Aluno getAluno(){
		return student;
	}
	
	public Curso getCurso(){
		return curse;
	}
	
	public int getNumber(){
		return number;
	}
	
	//---------------------------------------------------
	//-------------Setters-------------------------------
	//---------------------------------------------------
	public void setAluno(Aluno newStd){
		student = newStd;
	}
	
	public void setCurso(Curso newCrs){
		curse = newCrs;
	}
}//fim da classe Matricula
