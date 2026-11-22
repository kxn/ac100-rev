// func _uac_wserv_pkt_wlan_list_proc @ 005e78b0 size=1112

undefined4
_uac_wserv_pkt_wlan_list_proc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  char *__format;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_310;
  int local_30c;
  void *local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  
  if (*param_1 != 1) {
    if (g_wserv_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("<wserv>[error]%s(): %d  -> invalid wlan_list_val->wlan_op[%d]!\r\n",
           "_uac_wserv_pkt_wlan_list_proc",0x7b,*param_1);
    return 0;
  }
  if (param_1[1] == 0) {
    return 0;
  }
  iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2f0);
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_00408450(0xc,0x8b);
    if (piVar2 == (int *)0x0) {
      if (g_wserv_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("<wserv>[error]%s(): %d  -> no memory.\r\n","_uac_wserv_pkt_wlan_list_proc",0x8e);
      return 0xffffffff;
    }
    iVar1 = FUN_00408450(param_1[1] * 0x21,0x92);
    piVar2[2] = iVar1;
    if (iVar1 != 0) {
      piVar2[1] = 0;
      iVar1 = apmngr_db_capacity_support(local_2e0,1,4);
      piVar3 = piVar2;
      if ((iVar1 != 0) || (iVar1 = apmngr_db_capacity_support(local_2e0,1,0x33), iVar1 != 0))
      goto LAB_005e794c;
      piVar2[1] = param_1[1];
      memcpy((void *)piVar2[2],(void *)param_1[2],param_1[1] * 0x21);
      iVar1 = piVar2[1];
      goto LAB_005e7950;
    }
    uVar4 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> no memory.\r\n","_uac_wserv_pkt_wlan_list_proc",0x95);
      iVar1 = piVar2[2];
      goto LAB_005e7964;
    }
  }
  else {
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n",
             "_uac_wserv_pkt_wlan_list_proc",0x86);
    }
    piVar2 = param_1;
    piVar3 = (int *)0x0;
    if (g_wserv_debug != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        printf("<wserv>[debug]%s(): %d  -> del all bssid in ap!\r\n","_uac_wserv_pkt_wlan_list_proc"
               ,0x87);
        piVar3 = (int *)0x0;
      }
    }
LAB_005e794c:
    iVar1 = piVar2[1];
LAB_005e7950:
    uVar4 = 0;
    if (iVar1 != 0) {
      local_304 = 0;
      local_300 = 0;
      local_2fc = 0;
      local_2f8 = 0;
      local_2f4 = 0;
      local_310 = 0;
      local_30c = 0;
      local_308 = (void *)0x0;
      local_308 = (void *)FUN_00408450(piVar2[1] * 0x21,0x3d);
      if (local_308 == (void *)0x0) {
        if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = "<wserv>[error]%s(): %d  -> no memory.\r\n";
          uVar4 = 0x40;
LAB_005e7c94:
          printf(__format,"_uac_wserv_pkt_assemble_del_wlan_response_elem",uVar4);
        }
      }
      else {
        memset(local_308,0,piVar2[1] * 0x21);
        local_310 = 2;
        local_30c = piVar2[1];
        for (uVar5 = 0; iVar1 = uVar5 * 0x21, uVar5 < (uint)piVar2[1]; uVar5 = uVar5 + 1) {
          *(undefined1 *)((int)local_308 + iVar1) = *(undefined1 *)(piVar2[2] + iVar1);
          memcpy((void *)((int)local_308 + iVar1 + 1),(void *)(piVar2[2] + iVar1 + 1),0x20);
        }
        FUN_0051ad88(&local_2fc);
        local_304 = 0x12345678;
        local_300 = CONCAT22(0x1e,local_300._2_2_);
        iVar1 = cw_service_msg_add(param_4,0x25,&local_304,1,0x1e,&local_310);
        if (iVar1 == 0) {
          uVar4 = 0;
          if (local_308 != (void *)0x0) {
            FUN_00407df0();
          }
          goto LAB_005e7958;
        }
        if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = 
          "<wserv>[error]%s(): %d  -> set wservice wlan list del rslt vendor payload fail!\r\n";
          uVar4 = 0x58;
          goto LAB_005e7c94;
        }
      }
      if (local_308 != (void *)0x0) {
        FUN_00407df0();
      }
      uVar4 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> _uac_wsta_pkt_assemble_assoc_response_elem() fail.\r\n",
               "_uac_wserv_pkt_wlan_list_proc",0xa7);
      }
    }
LAB_005e7958:
    piVar2 = piVar3;
    if (piVar3 == (int *)0x0) {
      return uVar4;
    }
  }
  iVar1 = piVar2[2];
LAB_005e7964:
  if (iVar1 != 0) {
    FUN_00407df0();
    piVar2[2] = 0;
  }
  FUN_00407df0(piVar2);
  return uVar4;
}

