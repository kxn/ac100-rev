// func apmngr_ap_telnet_status_update @ 0052c358 size=512

undefined4 apmngr_ap_telnet_status_update(ushort *param_1,int param_2,char param_3)

{
  int iVar1;
  ushort uVar2;
  char *pcVar3;
  ushort *puVar4;
  int iVar5;
  undefined2 local_308 [4];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  int local_54;
  
  iVar5 = 0;
  memset(auStack_300,0,0x2d8);
  puVar4 = param_1;
  do {
    if (param_2 <= iVar5) {
      for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
        if (*param_1 != 0xffff) {
          apmngr_db_telnet_status_update(*param_1,param_3);
        }
        param_1 = param_1 + 1;
      }
      return 0;
    }
    iVar1 = apmngr_db_entry_get_by_id(*puVar4,auStack_300);
    if (iVar1 == 0) {
      if (apmngr_debug_switch == '\0') {
        uVar2 = *puVar4;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          uVar2 = *puVar4;
        }
        else {
          pcVar3 = "close";
          if (param_3 == '\x01') {
            pcVar3 = "open";
          }
          printf("[APMNGR_DEBUG]%s()/%d %s %d\'s telnet start\n","apmngr_ap_telnet_status_update",
                 0x586,pcVar3,(uint)*puVar4);
          uVar2 = *puVar4;
        }
      }
      apmngr_db_entry_telnet_set(uVar2,param_3 == '\x01');
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "close";
        if (param_3 == '\x01') {
          pcVar3 = "open";
        }
        printf("[APMNGR_DEBUG]%s()/%d %s %d\'s telnet_status finished\n",
               "apmngr_ap_telnet_status_update",0x589,pcVar3,(uint)*puVar4);
      }
      if ((1 < local_54 - 2U) || (iVar1 = multi_link_status_get(local_2f0), iVar1 == 0))
      goto LAB_0052c41c;
      apmngr_db_telnet_port_get(local_308);
      iVar1 = apmngr_telnet_config_send(local_2f0,param_3,local_308[0]);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
    else {
LAB_0052c41c:
      *puVar4 = 0xffff;
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
  } while( true );
}

