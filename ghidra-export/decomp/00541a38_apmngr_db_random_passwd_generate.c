// func apmngr_db_random_passwd_generate @ 00541a38 size=1

/* WARNING: Removing unreachable block (ram,0x00541a6c) */

void apmngr_db_random_passwd_generate(char *param_1)

{
  long lVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      lVar1 = random();
      *param_1 = (char)(lVar1 % 0x5e) + '!';
      param_1 = param_1 + 1;
    } while (iVar2 != 8);
  }
  return;
}

