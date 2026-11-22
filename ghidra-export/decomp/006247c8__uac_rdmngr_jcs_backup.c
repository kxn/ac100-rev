// func _uac_rdmngr_jcs_backup @ 006247c8 size=496

void _uac_rdmngr_jcs_backup(undefined4 param_1,undefined4 param_2)

{
  FILE *__s;
  int iVar1;
  undefined *__ptr;
  char *__format;
  size_t __size;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_backup() begin.\n","_uac_rdmngr_jcs_backup",0x460)
    ;
  }
  __s = fopen("/tmp/rdEntry.csv","a+");
  if (__s == (FILE *)0x0) {
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[RDMNGR_ERROR]%s()/%d open get file[%s] fail!\n";
      uVar2 = 0x464;
      pcVar3 = "/tmp/rdEntry.csv";
      goto LAB_0062496c;
    }
  }
  else {
    iVar1 = rdmngr_profile_support_rssi_kick();
    if (iVar1 == 0) {
      __size = 0x25e;
      __ptr = &DAT_0070b3d0;
    }
    else {
      __size = 0x284;
      __ptr = &DAT_0070b148;
    }
    fwrite(__ptr,__size,1,__s);
    iVar1 = apmngr_db_foreach_proc(0xf0000,_uac_rdmngr_foreach_backup_proc,__s);
    if (iVar1 != 1) {
      uVar2 = json_object_new_string("/tmp/rdEntry.csv");
      json_object_object_add(param_2,"file_name",uVar2);
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_backup() success.\n","_uac_rdmngr_jcs_backup",
               0x477);
      }
      fclose(__s);
      return;
    }
    if ((rdmngr_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[RDMNGR_WARNING]%s()/%d apmngr_db_foreach_proc_by_group() fail, ret=%d!\n";
      uVar2 = 0x472;
      pcVar3 = (char *)0x1;
LAB_0062496c:
      printf(__format,"_uac_rdmngr_jcs_backup",uVar2,pcVar3);
      return;
    }
  }
  return;
}

