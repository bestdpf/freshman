//Cracked by Roath
#include <ansi.h>
inherit ITEM;
string daoxing(int dx);
void create()
{
        set_name(HIR+"�ż�"+NOR, ({"xin letter", "letter"}));
        set("weight", 5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����ǧ�����и�����ż���\n");
                set("unit", "��");
                set("no_get", 1);
        }
        set("channel_id", "�ͱ�����");
        setup();
}



void init()
{
        add_action("do_give", "give");

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 6, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}
void set_owner(string owner)
{
        set("owner", owner);
}
int do_give(string arg)
{
        object me,ob;
        string obj,target;
        int i,qn;
       if(!arg || arg==" ")
            return 0;
        if (sscanf(arg,"%s to %s", obj, target)!=2 )
                if(sscanf(arg,"%s %s", target, obj) !=2 )       
                        return 0;

        if(!id(obj) )   return 0;

        me = this_player();
       
        if(!ob = present(target,environment(me)) ) {
                tell_object(me,"����Ҫ���ż�����˭��\n");
                return 1;
        }
        if( ob->short(1) != query("target")) {
                tell_object(me, "�㲻�ܰ��ż���������ˡ�\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"�Ѿ��޷��������������ˡ�\n");
                return 1;
        }
// ������˰�æ��������ͱ��˵��ż���bug
        if(!me->query("letter")||query("owner")!=me->query("id"))  {
        	write("�����Ͷ���ֵ�ù�������ϧû�б��꣬������\n");
        	 me->receive_damage("kee", 20);
                 me->receive_damage("sen", 20);
                 destruct(this_object());
                 return 1;
                 }
        message("vision",me->name()+"�ó�һ���ż�������" + ob->name() + "��\n", environment(me),({ me, ob }));
        if((time() > me->query( "letter/task_time" )) ) {
                tell_object(me,ob->name()+"���ż����˿��������ص�����һ�ۡ�\n");
                tell_object(me, "��û�м�ʱ���ż��͵�" + ob->query("name") + "�����У��������ʧ���ˣ�\n");
        } else {
                tell_object(me,ob->name()+"˵������л����л��\n");
                tell_object(me, "��ɹ��ذ��ż��͵���" + ob->name() + "�����С�\n");
                if(me->query("letter/basic")||me->query("combat_exp")<5000)
                i = 40+(int)( me->query("letter/task_time")-time())/10;
                else i = 50 + (int)(me->query("letter/task_time")-time())/7;
                i=i+random(40);
                me->add("daoxing",i);
                qn = 1+i/10;                
                me->add("potential",qn);
                tell_object(me, sprintf("������"HIR"%s"NOR"�ĵ��� ,"HIY"%s"NOR"��Ǳ�ܣ�\n"NOR, daoxing(i),chinese_number(qn)) );
                CHANNEL_D->do_channel(this_object(),"sys",NOR+me->name()+"���ż��͸�"+ob->name()+"���"HIR+daoxing(i)+NOR"�ĵ��У�"HIY+chinese_number(qn)+NOR"��Ǳ��\n");
                me->set("letter_over",time()+240+random(120));
                me->delete("letter");
        }
        if(me->query("kee")<=20||me->query("sen")<=20)
        { message_vision("$NͻȻ����ͷ���ۻ������������ۻ��ˣ�\n",me);
          me->unconcious();
         }
         else {
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        }
        destruct(this_object());
        return 1;
}
string daoxing(int dx)
{
	
	int day,hour;
	day = (dx) / 4;
	hour = (dx  - day * 4) * 3; 
	return day?(chinese_number(day)+"��"):""+hour?(chinese_number(hour)+"ʱ��"):"";
}
void owner_is_killed() { destruct(this_object()); }
