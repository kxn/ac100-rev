// func _apmngr_jcs_entry_backup @ 005495d4 size=472

void _apmngr_jcs_entry_backup(undefined4 param_1,undefined4 param_2)

{
  FILE *__s;
  int iVar1;
  undefined4 uVar2;
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d _apmngr_jcs_entry_backup() begin.\n","_apmngr_jcs_entry_backup",
           0x5d0);
  }
  __s = fopen("/tmp/apmngrExport.csv","a+");
  if (__s == (FILE *)0x0) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d open get file[%s] fail!\n","_apmngr_jcs_entry_backup",0x5d4,
             "/tmp/apmngrExport.csv");
      return;
    }
    return;
  }
  fwrite(&DAT_006cd968,0x1e5,1,__s);
  iVar1 = apmngr_db_foreach_proc(0xf0000,_apmngr_jcs_entry_backup_to_file,__s);
  if (((iVar1 == 1) && (apmngr_warning_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_WARNING]%s()/%d apmngr_db_foreach_proc_by_group() fail, ret=%d!\n",
           "_apmngr_jcs_entry_backup",0x5db,1);
  }
  uVar2 = json_object_new_string("/tmp/apmngrExport.csv");
  json_object_object_add(param_2,"file_name",uVar2);
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d _apmngr_jcs_entry_backup() success.\n","_apmngr_jcs_entry_backup",
           0x5df);
  }
  fclose(__s);
  return;
}

