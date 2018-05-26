# who-openport (wopnt)  

@Copyrights
 mrx6s0 - 2017 - github.com/mrx6s0

 # Classic [reverse] backdoor, writen in pure C. 
 # In desenvolpment. 
 
 # Join to this project,
 # contact me!
 
 @malw
 
are things;

 # Clássico backdoor reverso, escrito na linguagem C.
 # Em desenvolvimento.

"Quem abriu a porta?" 

Esse código tem por finalidade incluir um método de acesso a sistemas, remotamente, instalando o programa apenas uma vez na 
máquina. 

Garantido o acesso, o servidor poderá executar funções arbitrárias na máquina, e alterar o sistema. 

Depois de executado, o programa se encerra, ou seja, oculta-se como um processo qualquer, rodando como uma daemon, e mantém a conexão com o servidor. 

Para tal a implementação da shell deve estar conectada a algum sevidor. Não apenas uma shell, mas sim. uma REMOTE reverse-shell.

Diferentemente de outros backdoor open source, esse (permite) existe a conexão mesmo depois de encerrado o lado do cliente (backdoor).

Estou implementando aos poucos. Ajudas são bem vindas.

Desenvolpment of a backdoor write in C. 

# Funções: 

(#) desativar anti-vírus 

(#) desativar firewall 

(#) copiar o software para o registro da máquina alvo 

(#) copiar software para inicialização junto aos demais programas 

(#) fork para criar um deamon > usado em combinação com a reverse shell 


(em breve) enviar arquivo para a máquina alvo

(em breve) fazer download de arquivos da máquina

(em breve ) inicializar keylogger em modo passivo, enviando os arquivos para e-mail e/ou direto para o servidor. 

(em breve) informações sobre: ip, nome da máquina

(em breve) informações sobre: a rede da máquina alvo ( outras máquinas conectadas à mesma rede)

(em breve) mudar as configurações de proxy da máquina  

Para ver em ação, use o netcat. 

# nc -lvp 3389 

O backdoor se encerrará no mesmo momento, portanto, o servidor tem que estar na escuta na porta definida. 
Então, a conexão é garantida. 

Tudo depende de vossa criatividade, desse ponto em diante. 

     more to come! 
