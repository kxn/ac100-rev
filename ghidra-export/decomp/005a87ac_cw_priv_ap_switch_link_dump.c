// func cw_priv_ap_switch_link_dump @ 005a87ac size=188

undefined4 cw_priv_ap_switch_link_dump(int param_1)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  undefined4 auStack_28 [7];
  
  puVar3 = *(uint **)(param_1 + 0x10);
  memcpy(auStack_28,&PTR_s_Switch_to_backup_006e8aa0,0x14);
  printf("\t\t\tType: (t=%d,l=%d) private ap swtich link \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap swtich link (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*puVar3);
  uVar1 = *puVar3;
  if (uVar1 < 5) {
    pcVar2 = (char *)auStack_28[uVar1];
  }
  else {
    pcVar2 = "Unknown";
  }
  printf("\t\t\t\tprivate ap swtich link: %u(%s) \r\n ",uVar1,pcVar2);
  return 0;
}

