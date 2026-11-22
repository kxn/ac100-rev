// func _uac_lldp_jcs_get @ 004a37cc size=1096

void _uac_lldp_jcs_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  FILE *__s;
  size_t sVar2;
  int iVar3;
  int iVar4;
  void *__ptr;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_jcs_get begin............\n",
           "_uac_lldp_jcs_get",0x141);
  }
  __s = fopen("/tmp/lldp_get_info","w+");
  if (__s == (FILE *)0x0) {
    if (uac_lldp_err_switch != '\0') {
      printf("[UAC_LLDP_ERROR]%s()/%d open get file[%s] fail!\n","_uac_lldp_jcs_get",0x14c,
             "/tmp/lldp_get_info");
    }
    goto LAB_004a3858;
  }
  sVar2 = fwrite("[",1,1,__s);
  if (sVar2 != 1) {
    if (uac_lldp_err_switch == '\0') goto LAB_004a3858;
    uVar5 = 0x151;
LAB_004a394c:
    printf("[UAC_LLDP_ERROR]%s()/%d write result to file fail!\n","_uac_lldp_jcs_get",uVar5);
LAB_004a3858:
    FUN_00407f30(uac_lldp_mutex);
    if (__s != (FILE *)0x0) {
      fclose(__s);
    }
    if (uac_lldp_debug_switch == '\0') {
      return;
    }
    printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_jcs_get end............\n",
           "_uac_lldp_jcs_get",0x1b0);
    return;
  }
  FUN_004082d0(uac_lldp_mutex,0xffffffff);
  iVar3 = FUN_004081b0(&g_uac_lldp_list);
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d get_node%p g_total_cnt:%d!\n","_uac_lldp_jcs_get",0x158,iVar3,
           g_total_cnt);
  }
  iVar1 = g_total_cnt;
  iVar7 = 1;
  cVar6 = '\0';
LAB_004a399c:
  if ((iVar3 == 0) || (g_total_cnt < 1)) goto LAB_004a3ae8;
  if (*(int *)(iVar3 + 0x10) == 0) {
    iVar4 = *(int *)(iVar3 + 0x14);
    goto LAB_004a3a18;
  }
  if (*(int *)(iVar3 + 0x14) != 0) {
    if (0x73ff < (uint)(iVar7 + *(int *)(iVar3 + 0x10))) {
      if (uac_lldp_debug_switch != '\0') {
        printf("[UAC_LLDP_DEBUG]%s()/%d respone buf full!\n","_uac_lldp_jcs_get",0x166);
      }
LAB_004a3ae8:
      sVar2 = fwrite("]",1,1,__s);
      if (sVar2 == 1) {
        if ((g_is_continue == 0) || (5 < get_lldp_times)) {
          get_lldp_times = 0;
          uVar5 = 0;
        }
        else {
          if (iVar1 == 0) {
            get_lldp_times = get_lldp_times + 1;
          }
          else {
            get_lldp_times = 0;
          }
          uVar5 = 1;
        }
        uVar5 = json_object_new_int(uVar5);
        json_object_object_add(param_2,"continue",uVar5);
        uVar5 = json_object_new_string("/tmp/lldp_get_info");
        json_object_object_add(param_2,"get_lldp_info",uVar5);
        uVar5 = json_object_new_int(cVar6);
        json_object_object_add(param_2,"cnt",uVar5);
        goto LAB_004a3858;
      }
      if (uac_lldp_err_switch == '\0') goto LAB_004a3858;
      uVar5 = 0x18c;
      goto LAB_004a394c;
    }
    if ((cVar6 != '\0') && (sVar2 = fwrite(&DAT_00678b90,1,1,__s), sVar2 != 1)) {
      if (uac_lldp_err_switch == '\0') goto LAB_004a3858;
      uVar5 = 0x16e;
      goto LAB_004a394c;
    }
    if (uac_lldp_debug_switch == '\0') {
      __ptr = *(void **)(iVar3 + 0x14);
    }
    else {
      printf("[UAC_LLDP_DEBUG]%s()/%d write len:%d \r\ncon:%s to file !\n","_uac_lldp_jcs_get",0x173
             ,*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14));
      __ptr = *(void **)(iVar3 + 0x14);
    }
    sVar2 = fwrite(__ptr,*(size_t *)(iVar3 + 0x10),1,__s);
    if (sVar2 != 1) {
      if (uac_lldp_err_switch == '\0') goto LAB_004a3858;
      uVar5 = 0x176;
      goto LAB_004a394c;
    }
    cVar6 = cVar6 + '\x01';
    iVar7 = iVar7 + *(int *)(iVar3 + 0x10);
  }
  iVar4 = *(int *)(iVar3 + 0x14);
LAB_004a3a18:
  if (iVar4 != 0) {
    FUN_00407df0();
    *(undefined4 *)(iVar3 + 0x14) = 0;
  }
  FUN_00408500(iVar3);
  FUN_00407df0(iVar3);
  g_total_cnt = g_total_cnt + -1;
  iVar3 = FUN_004081b0(&g_uac_lldp_list);
  goto LAB_004a399c;
}

