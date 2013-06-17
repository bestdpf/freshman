
// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIC"大海无量"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("fork", j+random(15));
        me->set_skill("fengbo-cha", j+random(15));
        me->set_skill("hammer",j+random(15));
        me->set_skill("huntian-hammer",j+random(15));
        me->set_skill("dragonstep", j+random(15));
        me->set_skill("dragonfight", j+random(15));
        me->set_skill("dragonforce", j+random(15));
        me->set_skill("seashentong", j+random(15));

        me->map_skill("force", "dragonforce");
        me->map_skill("fork", "fengbo-cha");
        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "huntian-hammer");
        me->map_skill("spells", "seashentong");
        me->map_skill("dodge", "dragonstep");
        me->map_skill("unarmed", "dragonfight");
        create_family("东海龙宫", 2, "水族");
       set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "freez" :),
        (: cast_spell, "dragonfire" :),
        (: cast_spell, "shuidun" :),
//        (: exert_function, "roar" :),
//        (: exert_function, "shield" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/hammer/jingua");
        else
           weapon=new("/d/obj/weapon/fork/gangcha");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
