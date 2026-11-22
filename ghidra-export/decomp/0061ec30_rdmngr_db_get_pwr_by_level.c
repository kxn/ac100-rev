// func rdmngr_db_get_pwr_by_level @ 0061ec30 size=252

int rdmngr_db_get_pwr_by_level
              (double param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar1 = rdmngr_db_get_real_max_tx_pwr(param_3,param_5,param_6);
  iVar2 = param_4;
  if (((param_2 != 1) && (iVar2 = iVar1, param_2 != 10)) && (iVar2 = param_4, param_2 - 2U < 8)) {
    uVar3 = __floatsidf(iVar1 - param_4);
    uVar4 = __floatsidf(param_2 + -1);
    uVar3 = __muldf3((int)((ulonglong)uVar3 >> 0x20),(int)uVar3,(int)((ulonglong)uVar4 >> 0x20),
                     (int)uVar4);
    uVar3 = __divdf3((int)((ulonglong)uVar3 >> 0x20),(int)uVar3,0x40220000,0);
    round(param_1);
    uVar4 = __floatsidf(param_4);
    uVar3 = __adddf3((int)((ulonglong)uVar4 >> 0x20),(int)uVar4,(int)((ulonglong)uVar3 >> 0x20),
                     (int)uVar3);
    iVar2 = __fixdfsi((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  }
  return iVar2;
}

