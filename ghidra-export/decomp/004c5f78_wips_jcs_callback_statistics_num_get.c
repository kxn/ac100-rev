// func wips_jcs_callback_statistics_num_get @ 004c5f78 size=508

void wips_jcs_callback_statistics_num_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char acStack_120 [256];
  
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  FUN_004082d0(wips_global_mutex,0xffffffff);
  iVar1 = FUN_004081b0(&g_wips_list);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x98);
    while( true ) {
      switch(uVar2) {
      case 1:
      case 4:
        uVar3 = uVar3 + 1 & 0xffff;
        break;
      case 2:
      case 3:
        uVar4 = uVar4 + 1 & 0xffff;
        break;
      case 5:
        uVar5 = uVar5 + 1 & 0xffff;
        break;
      case 6:
        uVar6 = uVar6 + 1 & 0xffff;
      }
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      uVar2 = *(undefined4 *)(iVar1 + 0x98);
    }
  }
  FUN_00407f30(wips_global_mutex);
  memset(acStack_120,0,0x100);
  snprintf(acStack_120,0x100,"%d",uVar3);
  uVar2 = json_object_new_string(acStack_120);
  json_object_object_add(param_2,"threat_dev_num",uVar2);
  memset(acStack_120,0,0x100);
  snprintf(acStack_120,0x100,"%d",uVar5);
  uVar2 = json_object_new_string(acStack_120);
  json_object_object_add(param_2,"interfering_dev_num",uVar2);
  memset(acStack_120,0,0x100);
  snprintf(acStack_120,0x100,"%d",uVar6);
  uVar2 = json_object_new_string(acStack_120);
  json_object_object_add(param_2,"illegal_dev_num",uVar2);
  memset(acStack_120,0,0x100);
  snprintf(acStack_120,0x100,"%d",uVar4);
  uVar2 = json_object_new_string(acStack_120);
  json_object_object_add(param_2,"dos_attack_num",uVar2);
  return;
}

