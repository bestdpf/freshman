mudos+dtxy�İ�װ

�޸�options
cp options.h local_options
#define NO_WIZARDS �޸�Ϊ #undef NO_WIZARDS
#undef PACKAGE_UIDS �޸�Ϊ #define PACKAGE_UIDS
#define SENSIBLE_MODIFIERS �޸�Ϊ #undef SENSIBLE_MODIFIERS

mudos��װ
./build.MudOS ��develop����developģʽ�����gcc �Cg -DDEBUG -DDEBUG_MACROѡ�����gdb���ԡ�
gmake clean
gmake, ���󼰽��
gmake: *** No rule to make target `obj/malloc.o', needed by `driver'.  Stop.
������󲻹���������ִ��һ��gmake�Ϳ���ͨ����
socket_efuns.c: In function 'get_socket_addres':
socket_efuns.c:1198: error: invalid lvalue in unary '&'
gmake: *** [obj/socket_efuns.o] Error 1
Doing this change fixes the issue: 
 ���ǰ�ȡ��ַ��&�����Ƶ�?��������ȥ������gmake�Ϳ����ˡ�
��gmake��Ȼ��gmake install������

mud��������
�CD Ԥ����
�CN no_ip_demon ����Ҫ����address_server
�Cy  ��yydebug
�Cm ָ��mudlibĿ¼
�Cf  �Ƿ����master::flag����
�Ce  �Ƿ����preload�ļ�
�Cp �����˿�
�Cd ���Լ���
�Cc�Ƿ����������Ϣ
�Ct t_flag++ �Ƿ����call_heart_beat
dtxy��������

���staticĿ¼.  

ִ��ʱ�δ���*Wrong permissions for opening file /log/static/CRASHES for append.
��i < size �ĳ� i < sizeof(buf1)
Miscd.c 39�У���2nd argument to < is not numeric when the 1st is.

#define CFG_MAX_LOCAL_VARIABLES  25  �޸�Ϊ 100
ִ��ʱ�δ���*Error in loading object '/adm/daemons/combatd'
Log�ļ���/adm/daemons/combatd.c line 1343: Too many local variables before the end of line
/d/obj/misc/jitan.h�н�#define SHILI_D "/adm/daemons/shili" ������ǰ
������.c�ļ��е�include�ƶ���inheritǰ��
�½�toptenĿ¼��*Wrong permissions for opening file /data/topten/rich.o for overwrite.  "No such file or directory"

mudos�������̷���
set_defaults(rc.c) �����������ļ�������ϵͳ����
init_addr_server ����ʼ��address server 
init_simul_efun��init_master()��װ��mudlib��simul_efun��master
preload_objects ��Ԥ���ض���
����master��APPLY_EPILOG�����������ļ��б�
����master��APPLY_PRELOAD���������ض���

backend(backend.c)
init_user_conn ��ʼ���û�����, ���÷�����ģʽ������. 
ѭ������select������ȡ��дʱ��
process_io(comm.c) ����io����
new_user_handler�����external_port�пɶ����ݣ��������û�����
 /adm/object/master.connect()  /obj/login.logon()  /adm/daemon/logind.logon()
�û������е�socket����пɶ����ݣ�get_user_data
��ȡsocket���ݣ�����buf��
cmd_in_buf�������棬���buf�������з���������cmd�ı��λ
�û������е�socket����п�д���ݣ�flush_message
����efun_socket�ϵ�socket����
����address server������
process_user_command (comm..c) �����û�����
get_user_command ��ȡ�û�����
call_function_interactive ִ������
