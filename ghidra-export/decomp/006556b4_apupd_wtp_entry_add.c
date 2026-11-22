// func apupd_wtp_entry_add @ 006556b4 size=1168

undefined4 apupd_wtp_entry_add(int param_1)

{
  int iVar1;
  void *__s;
  int iVar2;
  int iVar3;
  char cVar5;
  int iVar4;
  void *__s_00;
  char *pcVar6;
  undefined4 uVar7;
  
  if (((param_1 == 0) || (apupd_wtp_hash == 0)) || (apupd_model_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar7 = 0xed9;
    goto LAB_006558e8;
  }
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1 + 0x34);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: model isn\'t existent.\r\n";
    uVar7 = 0xee0;
    goto LAB_006558e8;
  }
  __s = (void *)FUN_00408450(0xa0,0xee5);
  if (__s == (void *)0x0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: malloc wtp failed.\r\n";
    uVar7 = 0xee8;
    goto LAB_006558e8;
  }
  memset(__s,0,0xa0);
  iVar2 = apupd_wtp_entry_clone(__s,param_1);
  if (iVar2 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[APUPD_ERROR]%32s() %05d: clone wtp failed.\r\n";
    uVar7 = 0xef0;
    goto LAB_006558e8;
  }
  *(int *)((int)__s + 0x50) = iVar1;
  FUN_004086b0(iVar1 + 0x7f4,__s);
  FUN_004086b0(apupd_wtp_list,(int)__s + 0xc);
  iVar2 = FUN_00408380(apupd_wtp_hash,__s);
  if (iVar2 != 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: add wtp to hash failed.\r\n","apupd_wtp_entry_add",0xefa);
    }
    FUN_00408500(__s);
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  iVar2 = FUN_00407fa0(apupd_hwid_hash,iVar1 + 0x119);
  if (iVar2 == 0) {
    apupd_update_hw_fw_info(0,__s,0,iVar1);
    cVar5 = *(char *)(iVar1 + 0x138);
  }
  else {
    iVar3 = apupd_check_from_vap
                      (*(undefined4 *)((int)__s + 0x18),*(undefined4 *)((int)__s + 0x1c),
                       *(undefined4 *)((int)__s + 0x20),*(undefined4 *)((int)__s + 0x24),
                       *(undefined4 *)((int)__s + 0x28));
    if ((iVar3 == 0) && (*(char *)(iVar1 + 0x138) != '\x02')) {
      for (iVar3 = FUN_004081b0(*(undefined4 *)(iVar2 + 0x10)); iVar3 != 0;
          iVar3 = FUN_00408680(iVar3)) {
        iVar4 = memcmp((void *)(iVar3 + 0xc),(void *)((int)__s + 0x58),0x10);
        if (iVar4 == 0) {
          *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
          goto LAB_006557c0;
        }
      }
      __s_00 = (void *)FUN_00408450(0x20,0xf1c);
      if (__s_00 == (void *)0x0) {
        if (g_apupd_error == 0) {
          cVar5 = *(char *)(iVar1 + 0x138);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            pcVar6 = "[APUPD_ERROR]%32s() %05d: uac_mem_malloc failed.\r\n";
            uVar7 = 0xf1f;
            goto LAB_006559a0;
          }
          cVar5 = *(char *)(iVar1 + 0x138);
        }
      }
      else {
        memset(__s_00,0,0x20);
        memcpy((void *)((int)__s_00 + 0xc),(void *)((int)__s + 0x58),0x10);
        *(undefined4 *)((int)__s_00 + 0x1c) = 1;
        FUN_004086b0(*(undefined4 *)(iVar2 + 0x10),__s_00);
        if (DAT_007cc7c8 != -1) {
          FUN_00408060();
          DAT_007cc7c8 = -1;
        }
        DAT_007cc7c8 = FUN_00408340(g_apupd_report_interval,0,apupd_report_hw_fw_to_cloud_callback,0
                                    ,0,"apupd_wtp_entry_add",0xf30);
        if (DAT_007cc7c8 != -1) goto LAB_006557c0;
        if (g_apupd_error == 0) {
          cVar5 = *(char *)(iVar1 + 0x138);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            pcVar6 = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
            uVar7 = 0xf33;
            goto LAB_006559a0;
          }
          cVar5 = *(char *)(iVar1 + 0x138);
        }
      }
    }
    else if (g_apupd_debug == 0) {
LAB_006557c0:
      cVar5 = *(char *)(iVar1 + 0x138);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        cVar5 = *(char *)(iVar1 + 0x138);
      }
      else {
        pcVar6 = "[APUPD_DEBUG]%32s() %05d: new wtp is from vap(or sensor),just it.\r\n";
        uVar7 = 0xf3a;
LAB_006559a0:
        printf(pcVar6,"apupd_wtp_entry_add",uVar7);
        cVar5 = *(char *)(iVar1 + 0x138);
      }
    }
  }
  if (cVar5 == '\x01') {
    return 0;
  }
  if (cVar5 == '\x03') {
    return 0;
  }
  iVar1 = apupd_wtp_entry_add_after_handle(__s);
  if (iVar1 != -1) {
    return 0;
  }
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar6 = "[APUPD_ERROR]%32s() %05d: handle wtp after adding failed.\r\n";
  uVar7 = 0xf42;
LAB_006558e8:
  printf(pcVar6,"apupd_wtp_entry_add",uVar7);
  return 0xffffffff;
}

