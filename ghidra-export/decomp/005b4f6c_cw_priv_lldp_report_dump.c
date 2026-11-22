// func cw_priv_lldp_report_dump @ 005b4f6c size=100

undefined4 cw_priv_lldp_report_dump(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  printf("\t\t\tlen: %d \r\n",*piVar1);
  if ((piVar1[1] == 0) || (*piVar1 == 0)) {
    puts("\t\t\tdata: is null \r");
  }
  else {
    printf("\t\t\tdata:%s\r\n");
  }
  return 0;
}

