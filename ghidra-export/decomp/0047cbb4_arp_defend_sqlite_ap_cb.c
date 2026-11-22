// func arp_defend_sqlite_ap_cb @ 0047cbb4 size=900

undefined4 arp_defend_sqlite_ap_cb(void *param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  char *__s1;
  uint local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined1 auStack_300 [728];
  
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  memset(auStack_300,0,0x2d8);
  if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d column is %d\n","arp_defend_sqlite_ap_cb",0x152,param_2);
  }
  if (param_1 == (void *)0x0) {
    uVar8 = 0;
    if (arp_defend_err_switch == 0) {
      return 0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0;
    }
    pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d para is null.\n";
    uVar6 = 0x156;
  }
  else {
    bVar2 = false;
    iVar4 = 0;
    memset(param_1,-1,DAT_007670f0 << 2);
    bVar1 = 0 < param_2;
    while (bVar1) {
      pcVar5 = (char *)*param_3;
      if ((pcVar5 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
        uVar8 = 1;
        if (arp_defend_err_switch == 0) {
          return 1;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 1;
        }
        pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d column value or name is null.\n";
        uVar6 = 0x161;
        goto LAB_0047cf08;
      }
      iVar3 = strcmp(__s1,"ap_id");
      if (iVar3 == 0) {
        local_310 = atoi(pcVar5);
        iVar3 = apmngr_db_entry_get_by_id(local_310 & 0xffff,auStack_300);
        if (((iVar3 != 0) && (bVar2 = true, arp_defend_err_switch != 0)) &&
           (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d apmngr_db_entry_get_by_id(%d) fail.\n";
          uVar8 = 0x16a;
          uVar7 = local_310;
LAB_0047cd88:
          bVar2 = true;
          printf(pcVar5,"arp_defend_sqlite_ap_cb",uVar8,uVar7);
        }
      }
      else {
        iVar3 = strcmp(__s1,"enable");
        if (iVar3 == 0) {
          iVar3 = atoi(pcVar5);
          local_30c = CONCAT13((char)iVar3,local_30c._1_3_);
        }
        else {
          iVar3 = strcmp(__s1,"bind_id_list");
          if (iVar3 == 0) {
            iVar3 = arp_defend_bind_arp(pcVar5,param_1,1,&local_308);
            if (((iVar3 != 0) && (bVar2 = true, arp_defend_err_switch != 0)) &&
               (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_bind_arp(%s) fail.\n";
              uVar8 = 0x176;
              uVar7 = *param_3;
              goto LAB_0047cd88;
            }
          }
          else {
            iVar3 = strcmp(__s1,"key");
            if (iVar3 != 0) {
              if (arp_defend_err_switch == 0) {
                return 1;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                return 1;
              }
              printf("[ARP_DEFEND_ERROR]%s()/%d Invalid column_name[%s]\n","arp_defend_sqlite_ap_cb"
                     ,0x180,*param_4);
              return 1;
            }
          }
        }
      }
      iVar4 = iVar4 + 1;
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
      bVar1 = iVar4 < param_2;
    }
    if (bVar2) {
      FUN_00407ec0(local_310,g_invalid_arp_ap_id,&g_invalid_arp_ap_id_pos);
      return 0;
    }
    iVar4 = arp_defend_db_ap_entry_set(&local_310,param_1);
    if (iVar4 == 0) {
      return 0;
    }
    uVar8 = 1;
    if (arp_defend_err_switch == 0) {
      return 1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 1;
    }
    pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_load_ap_service() failed.\n";
    uVar6 = 0x18d;
  }
LAB_0047cf08:
  printf(pcVar5,"arp_defend_sqlite_ap_cb",uVar6);
  return uVar8;
}

