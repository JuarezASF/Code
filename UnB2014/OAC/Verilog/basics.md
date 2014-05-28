#Verilog - Básico

* verilog é uma **HDL** : hardware description language
* As caixas pretas que permitem vizualizar o hardware em alto nível são chamadas **módulos** ou **module**'s. 
* **module** é uma palavra reservada em verilog: são objetos com entrada, saída e um circuito lógico em seu interior. De certa forma, são como as rotinas de outas linguagens de programação.

## Definindo um Módulo
* sintaxe:

        module moduleName(porta1, porta2, ..., portaN);
        input porta1;
        input porta2;
        ...
        output portak;
        ...
        output portaN;
        // comentário
        ....
        endmodule
        
notar que:

1. comandos e definições terminam com ';'
2. '//' inicia um comentário
3. primeir definimos todas as portas que se conectam com um módulo e em seguida definimos se são de entrada ou se saída.
4. Também é possível ter uma porta de entrada e saída. para isso usamosa palavra **inout**
5. No verilog 2001 é possível definir se a porta é de entrada ou saida junto com a sua declaração

## Entradas do tipo Vetor e Endianess
E se a porta1 for um conjunto de bits e não apenas um bit?
* a declaração no cabeçalho do módulo é feita da mesma forma
* a diferença está na hora de declarar o tipo(input ou output)
* para declarar um vetor, faça:
    
        input [7:0] address;
        
*veja que [7:0] é diferente é [0:7]. A primeira notação é little-endian e a segunda big-endian.

## Tipos básicos de dados
Os tipos básicos de dados em verilog representam as diferenças físicas entre os componentes de um circuito. Basicamente temos 2 tipos:
* **reg** : para **reg**istradores. utilizado para salvar dados.
* **wire** : para fios(**wire**s). é utilizado para conectar dois pontos.

Os outros tipos são vairações destes, por exemplo, um registrador pode ser signed ou unsigned e por aí vai.
exemplo:

        wire and_gate_output; // "and_gate_output" is a wire that only outputs
        reg d_flip_flop_output; // "d_flip_flop_output" is a register; it stores and outputs a value
        reg [7:0] address_bus; // "address_bus" is a little-endian 8-bit register
        
**note como um registrador de 7 bits foi declarado! Isso será útil mais tarde!!!**

## Operadores
Os operadores são os mesmos, ou quase os mesmos, de C. Aqui vai uma tabela para consulta:

Operator Type | Operator Symbol | Operation Performed |
--------------|-----------------|---------------------|
Arithmetic  |* |Multiply|
| | / | Division|
| |  + |  Add |
| |  -  | Subtract |
| |  %  | Modulus
| |  +  | Unary plus
| |  - |  Unary minus
Logical | |
| |  ! |  Logical negation
| |  && |  Logical and
| |  || |  Logical or   
| Relational | |
|  | > |  Greater than
| |  < |  Less than
|  | >= |  Greater than or equal
|  | <= |  Less than or equal
Equality | |
|  | == |  Equality
|  | != |  inequality
Reduction |  | 
|  | ~ |  Bitwise negation
|  | ~& |  nand
|  | |  | or
|  | ~|  | nor
|  | ^  | xor
|  | ^~ |  xnor
|  | ~^ |  xnor
Shift  |  |  
|  | >> |  Right shift 
| |  << |  Left shift
Concatenation |  | 
| | { } |  Concatenation
Conditional | |
|  | ?  | conditional 

##Blocos de código

Verilog não utiliza {}'s para reconhecer blocos de código, ele utiliza estrutura begin/end. Exepmlo:

    if (enable == 1'b1) begin
         data = 10; // Decimal assigned
         address = 16'hDEAD; // Hexadecimal
         wr_enable = 1'b1; // Binary  
       end else begin
         data = 32'b0;
         wr_enable = 1'b0;
         address = address + 1;  
     end
     

