// func mesh_db_discover_list_add_test @ 004ba2ac size=1

void mesh_db_discover_list_add_test
               (undefined2 param_1,undefined4 param_2,char *param_3,int param_4,int param_5)

{
  undefined1 uVar2;
  int iVar1;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined2 auStack_48 [2];
  undefined4 uStack_44;
  undefined1 uStack_40;
  char cStack_3f;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined1 uStack_38;
  undefined3 uStack_37;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  
  uVar2 = 1;
  if (param_5 != 1) {
    uVar2 = 2;
  }
  _uStack_38 = CONCAT13(uVar2,0xc90000);
  auStack_48[0] = 0;
  uStack_44 = 0;
  cStack_3f = '\0';
  uStack_40 = 0;
  uStack_34 = 0;
  uStack_3c = param_1;
  uStack_3a = param_1;
  iVar1 = sscanf(param_3,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_30,auStack_2c,auStack_28,auStack_24,
                 auStack_20,auStack_1c);
  if (iVar1 == 6) {
    puVar3 = &uStack_30;
    iVar1 = 0;
    do {
      puVar4 = (undefined1 *)((int)&uStack_44 + iVar1);
      uVar5 = *puVar3;
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
      *puVar4 = (char)uVar5;
    } while (iVar1 != 6);
    for (iVar1 = 0; iVar1 < param_4; iVar1 = iVar1 + 1) {
      mesh_db_discover_list_add(&uStack_44,param_2,auStack_48,0,1,1,&uStack_3c);
      cStack_3f = cStack_3f + '\x01';
    }
  }
  else {
    puts("parameter is wrong");
  }
  return;
}

