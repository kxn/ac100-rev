// func apmngr_ap_led_update @ 0052c558 size=872

undefined4 apmngr_ap_led_update(ushort *param_1,int param_2,int param_3)

{
  int iVar1;
  uint *__s;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  ushort *puVar5;
  uint *puVar6;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  char local_1d0;
  char local_144;
  uint local_ac;
  int local_78;
  int local_54;
  
  memset(auStack_300,0,0x2d8);
  if ((param_1 != (ushort *)0x0) && (0 < param_2)) {
    local_310 = 0;
    local_30c = 0;
    local_308 = 0;
    local_304 = 0;
    iVar1 = serv_wtp_address_arg_init(&local_310);
    if (iVar1 == 0) {
      __s = (uint *)FUN_00408450(param_2 << 2,0x5b9);
      if (__s != (uint *)0x0) {
        iVar1 = 0;
        memset(__s,0,param_2 << 2);
        puVar5 = param_1;
        puVar6 = __s;
        do {
          iVar2 = apmngr_db_entry_get_by_id(*puVar5,auStack_300);
          if (iVar2 == 0) {
            if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar4 = "close";
              if (param_3 == 1) {
                pcVar4 = "open";
              }
              printf("[APMNGR_DEBUG]%s()/%d %s %d\'s led start\n","apmngr_ap_led_update",0x5c7,
                     pcVar4,(uint)*puVar5);
            }
            if (local_144 == '\0') {
              apmngr_db_entry_led_set(*puVar5,param_3 == 1);
            }
            if ((((local_78 == 0) || (local_78 == param_3)) || (1 < local_54 - 2U)) ||
               (iVar2 = multi_link_status_get(local_2f0), iVar2 == 0)) goto LAB_0052c668;
            if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar4 = "close";
              if (param_3 == 1) {
                pcVar4 = "open";
              }
              printf("[APMNGR_DEBUG]%s()/%d %s %d\'s led finished\n","apmngr_ap_led_update",0x5da,
                     pcVar4,(uint)*puVar5);
            }
            uVar3 = 0;
            if (((local_ac & 0x400) != 0) && (param_3 == 2)) {
              uVar3 = (uint)(local_1d0 != '\0');
            }
            *puVar6 = uVar3;
            apmngr_db_get_addr_by_capacity(local_2f0,&local_310,1,1,0xffffffff,0);
          }
          else {
LAB_0052c668:
            *puVar5 = 0xffff;
          }
          iVar1 = iVar1 + 1;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
          if (iVar1 == param_2) {
            iVar1 = apmngr_pkt_led_pkt_send(&local_310,param_3 == 1);
            iVar2 = 0;
            puVar6 = __s;
            if (iVar1 != 0) {
              if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[APMNGR_ERROR]%s()/%d Failed to send led change packet.\n",
                       "apmngr_ap_led_update",0x5e2);
              }
              FUN_00407df0(__s);
              serv_wtp_address_arg_destroy(&local_310);
              return 0xffffffff;
            }
            do {
              if (((*param_1 != 0xffff) && (apmngr_db_ap_led_update(*param_1,param_3), *puVar6 != 0)
                  ) && (iVar1 = apmngr_db_entry_get_by_id(*param_1,auStack_300), iVar1 == 0)) {
                apmngr_evt_notify(6,auStack_300);
              }
              iVar2 = iVar2 + 1;
              param_1 = param_1 + 1;
              puVar6 = puVar6 + 1;
            } while (iVar2 != param_2);
            FUN_00407df0(__s);
            serv_wtp_address_arg_destroy(&local_310);
            return 0;
          }
        } while( true );
      }
    }
    serv_wtp_address_arg_destroy(&local_310);
  }
  return 0xffffffff;
}

