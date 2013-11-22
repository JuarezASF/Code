package ClassesBásicas;

public class Curso {
	private String code, name, teacher;
	private int numberStudents;
	
		//---------------------------------------------------
		//-------------Construtores--------------------------
		//---------------------------------------------------
		public Curso(String newCd, String newNm, String newTch){
			setName(newNm);
			setCode(newCd);
			setTeacher(newTch);
			setNStudents(0);
		}

		public Curso(String newCd){
			setName("Não informado");
			setCode(newCd);
			setTeacher("Não informado");
			setNStudents(0);
		}
		//---------------------------------------------------
		//-------------Getters-------------------------------
		//---------------------------------------------------
		public String getName(){
			return name;
		}
		
		public String getCode(){
			return code;
		}
		
		public String getTeacher(){
			return teacher;
		}
		public int getNStudents(){
			return numberStudents;
		}		
		//---------------------------------------------------
		//-------------Setters-------------------------------
		//---------------------------------------------------
		public void setName(String newNm){
			name = newNm;
		}
		
		public void setCode(String newCd){
			code = newCd;
		}
		
		public void setTeacher(String newTch){
			teacher = newTch;
		}

		public void setNStudents(int newNS){
			numberStudents = newNS;
		}
		public void incrementNStudents(){
			numberStudents++;
		}
		public void decrementNStudents(){
			numberStudents--;
		}		
}//fim da classe Curso
