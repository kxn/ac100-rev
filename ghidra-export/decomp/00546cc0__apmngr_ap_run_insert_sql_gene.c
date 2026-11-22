// func _apmngr_ap_run_insert_sql_gene @ 00546cc0 size=296

size_t _apmngr_ap_run_insert_sql_gene(char *param_1,size_t param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  
  uVar1 = *(ushort *)(param_3 + 0x10);
  uVar2 = *(ushort *)(param_3 + 0x12);
  uVar3 = apmngr_db_role_str(*(undefined4 *)(param_3 + 0x14));
  iVar4 = snprintf(param_1,param_2,
                   "INSERT INTO %s (%s, %s, %s, %s, %s, %s, %s, %s) VALUES(%d, %d, \'%s\', %u, %d, %d, %d, 0);"
                   ,"ApEntryRun_table","entry_id","group_id","ap_role",&DAT_006cb294,"status","led",
                   "telnet_status","errno",(uint)uVar1,(uint)uVar2,uVar3,
                   (uint)*(byte *)(param_3 + 0x3f),*(undefined4 *)(param_3 + 0x2ac),0,
                   (uint)*(byte *)(param_3 + 0x295));
  if (-1 < iVar4) {
    sVar5 = strlen(param_1);
    return sVar5;
  }
  return 0xffffffff;
}

