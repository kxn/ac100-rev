// func _get_bind_svr_json @ 0046150c size=628

undefined4
_get_bind_svr_json(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_120;
  char acStack_11c [264];
  
  memset(acStack_11c,0,0x100);
  local_120 = 0;
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    param_4 = 0x680;
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_get_bind_svr_json",0x680,
           "_get_bind_svr_json");
  }
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    uVar4 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_get_bind_svr_json",0x681,"svr_entry && p_arg");
    }
  }
  else {
    iVar3 = json_object_new_object();
    if (iVar3 == 0) {
      uVar4 = 0xffffffff;
      if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend","_get_bind_svr_json",
               0x686);
      }
    }
    else {
      uVar1 = (uint)param_1 & 3;
      uVar2 = (int)param_1 + 3U & 3;
      snprintf(acStack_11c,0x100,"%d",
               (*(int *)((int)param_1 - uVar1) << uVar1 * 8 |
               param_4 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)(((int)param_1 + 3U) - uVar2) >> (3 - uVar2) * 8);
      uVar4 = json_object_new_string(acStack_11c);
      json_object_object_add(iVar3,"svr_id",uVar4);
      snprintf(acStack_11c,0x100,"%s",param_1 + 1);
      uVar4 = json_object_new_string(acStack_11c);
      json_object_object_add(iVar3,"name",uVar4);
      snprintf(acStack_11c,0x100,"%d",(int)*(char *)((int)param_1 + 0x9b));
      uVar4 = json_object_new_string(acStack_11c);
      json_object_object_add(iVar3,"addr_type",uVar4);
      dhcpdef_addr2str((int)*(char *)((int)param_1 + 0x9b),param_1 + 0x27,acStack_11c);
      uVar4 = json_object_new_string(acStack_11c);
      json_object_object_add(iVar3,"svr_addr",uVar4);
      uVar4 = 0;
      dhcpdef_db_svr_entry_is_binded_to_ap(*param_2,*param_1,&local_120);
      snprintf(acStack_11c,0x100,"%d",(uint)(local_120 != 0));
      uVar5 = json_object_new_string(acStack_11c);
      json_object_object_add(iVar3,"bind_status",uVar5);
      json_object_array_add(param_2[8],iVar3);
    }
  }
  return uVar4;
}

