// func _uac_wsta_jcs_backup @ 00630828 size=496

void _uac_wsta_jcs_backup(undefined4 param_1,undefined4 param_2)

{
  FILE *__s;
  int iVar1;
  undefined4 uVar2;
  
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_backup() begin.\r\n","_uac_wsta_jcs_backup",
           0x4aa);
  }
  __s = fopen("/tmp/apmng_client.csv","a+");
  if (__s == (FILE *)0x0) {
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("<wsta>[error]%s(): %d  -> /tmp/apmng_client.csv\r\n","_uac_wsta_jcs_backup",0x4ae);
      return;
    }
    return;
  }
  fwrite(&DAT_0070ccb8,0x6b,1,__s);
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_get() begin.\r\n","_uac_wsta_jcs_backup",0x4b4);
  }
  iVar1 = apmngr_db_foreach_proc(0xf0000,_uac_wta_backup_entry_for_each_cb,__s);
  if (iVar1 == 1) {
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> apmngr_db_foreach_proc() fail, ret=%d!\r\n",
             "_uac_wsta_jcs_backup",0x4b9,1);
    }
  }
  else {
    uVar2 = json_object_new_string("/tmp/apmng_client.csv");
    json_object_object_add(param_2,"file_name",uVar2);
    if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[debug]%s(): %d  -> wportal_jcs_backup_callback() success.\r\n",
             "_uac_wsta_jcs_backup",0x4be);
    }
  }
  fclose(__s);
  return;
}

