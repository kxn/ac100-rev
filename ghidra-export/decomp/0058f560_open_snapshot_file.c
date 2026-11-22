// func open_snapshot_file @ 0058f560 size=176

undefined4 open_snapshot_file(char *param_1,int param_2)

{
  int iVar1;
  FILE *pFVar2;
  
  if ((param_2 != 0) && (*(FILE **)(g_write_snapshot_data + 0x1c) != (FILE *)0x0)) {
    fclose(*(FILE **)(g_write_snapshot_data + 0x1c));
    *(undefined4 *)(g_write_snapshot_data + 0x1c) = 0;
  }
  iVar1 = g_write_snapshot_data;
  if (*(int *)(g_write_snapshot_data + 0x1c) == 0) {
    pFVar2 = fopen("/tmp/pkt_snapshot.csv",param_1);
    *(FILE **)(iVar1 + 0x1c) = pFVar2;
  }
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d %p\n","open_snapshot_file",0xccf,
           *(undefined4 *)(g_write_snapshot_data + 0x1c));
  }
  return *(undefined4 *)(g_write_snapshot_data + 0x1c);
}

