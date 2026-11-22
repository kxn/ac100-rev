// func apdb_parse_test @ 0060d290 size=296

void apdb_parse_test(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int local_50;
  int local_4c [10];
  
  bVar1 = false;
  memset(&local_50,0,0x28);
  if (param_1 == (char *)0x0) {
    param_1 = (char *)FUN_00408450(0x40,0x2f3d);
    if (param_1 == (char *)0x0) {
      printf("no momery");
      return;
    }
    memset(param_1,0,0x40);
    bVar1 = true;
    strcpy(param_1,"chnl,rdMd,bwMd,wmm,brd,maxUsr,rssi,dcs");
  }
  piVar3 = &local_50;
  _apdb_parse_linked_modify_items(param_1,&local_50);
  iVar4 = 0;
  while( true ) {
    pcVar2 = "True";
    if (local_50 == 0) {
      pcVar2 = "False";
    }
    piVar3 = piVar3 + 1;
    printf("items[%d] is %s\n",iVar4,pcVar2);
    if (iVar4 + 1 == 10) break;
    local_50 = *piVar3;
    iVar4 = iVar4 + 1;
  }
  if (bVar1) {
    FUN_00407df0(param_1);
  }
  return;
}

