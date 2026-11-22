// func recreate_new_file @ 00594580 size=208

undefined4 recreate_new_file(void)

{
  FILE *__s;
  undefined4 uVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  local_10 = 0xef;
  local_f = 0xbb;
  local_e = 0xbf;
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d recreate_new_file\n","recreate_new_file",0x5e);
  }
  rename("/tmp/pkt_snapshot.csv","/tmp/old_pkt_snapshot.csv");
  __s = (FILE *)open_snapshot_file(&DAT_00676fc0,1);
  uVar1 = 0xffffffff;
  if (__s != (FILE *)0x0) {
    fwrite(&local_10,1,3,__s);
    fflush(__s);
    fwrite(&DAT_006dec98,0x159,1,__s);
    close_snapshot_file();
    uVar1 = 0;
  }
  return uVar1;
}

