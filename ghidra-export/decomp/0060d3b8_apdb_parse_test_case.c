// func apdb_parse_test_case @ 0060d3b8 size=1

void apdb_parse_test_case(int param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iStack_50;
  int aiStack_4c [9];
  
  memset(&iStack_50,0,0x28);
  if (param_1 == 0) {
    param_1 = 0x35001401;
  }
  piVar3 = &iStack_50;
  apdb_get_24g_linked_modify_items(param_1,param_2,&iStack_50);
  iVar1 = iStack_50;
  piVar4 = piVar3;
  iVar5 = 0;
  while( true ) {
    pcVar2 = "True";
    if (iVar1 == 0) {
      pcVar2 = "False";
    }
    piVar4 = piVar4 + 1;
    printf("2.4G items[%d] is %s\n",iVar5,pcVar2);
    if (iVar5 + 1 == 10) break;
    iVar1 = *piVar4;
    iVar5 = iVar5 + 1;
  }
  memset(&iStack_50,0,0x28);
  apdb_get_5g_linked_modify_items(param_1,param_2,&iStack_50);
  iVar1 = 0;
  while( true ) {
    pcVar2 = "True";
    if (iStack_50 == 0) {
      pcVar2 = "False";
    }
    piVar3 = piVar3 + 1;
    printf("5G items[%d] is %s\n",iVar1,pcVar2);
    if (iVar1 + 1 == 10) break;
    iStack_50 = *piVar3;
    iVar1 = iVar1 + 1;
  }
  return;
}

