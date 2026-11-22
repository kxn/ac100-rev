// func _multi_link_pkt_discover_or_join_req_listen @ 00663500 size=200

undefined4
_multi_link_pkt_discover_or_join_req_listen
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_58;
  char *local_54;
  char acStack_50 [68];
  
  local_58 = 0;
  local_54 = (char *)0x0;
  memset(acStack_50,0,0x40);
  strncpy(acStack_50,&g_multi_link_ac_name,0x3f);
  uVar3 = 0;
  local_54 = acStack_50;
  sVar1 = strlen(acStack_50);
  local_58 = CONCAT22(local_58._0_2_,(short)sVar1 + 1);
  local_58 = CONCAT13(g_multi_link_priority,local_58._1_3_);
  iVar2 = cw_service_msg_add(param_3,5,&local_58,0);
  if ((iVar2 != 0) && (uVar3 = 0xffffffff, multi_link_err_switch != '\0')) {
    printf("[MULTI_LINK_ERROR]%s()/%d Failed to insert vendor-specific elements for config status response.\n"
           ,"_multi_link_pkt_discover_or_join_req_listen",0x13d);
  }
  return uVar3;
}

