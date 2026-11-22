// func rb_erase @ 0051f320 size=1056

void rb_erase(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  code *pcVar6;
  
  puVar2 = (uint *)param_1[1];
  if ((uint *)param_1[2] == (uint *)0x0) {
    uVar1 = *param_1;
  }
  else {
    if (puVar2 != (uint *)0x0) {
      puVar3 = puVar2;
      for (puVar5 = (uint *)puVar2[2]; puVar5 != (uint *)0x0; puVar5 = (uint *)puVar5[2]) {
        puVar3 = puVar5;
      }
      uVar1 = *param_1 & 0xfffffffc;
      if (uVar1 == 0) {
        *param_2 = puVar3;
      }
      else if (*(uint **)(uVar1 + 8) == param_1) {
        *(uint **)(uVar1 + 8) = puVar3;
      }
      else {
        *(uint **)(uVar1 + 4) = puVar3;
      }
      puVar2 = (uint *)puVar3[1];
      puVar4 = (uint *)(*puVar3 & 0xfffffffc);
      uVar1 = *puVar3 & 1;
      puVar5 = puVar3;
      if (puVar4 != param_1) {
        if (puVar2 == (uint *)0x0) {
          puVar4[2] = 0;
        }
        else {
          *puVar2 = *puVar2 & 3 | (uint)puVar4;
          puVar4[2] = (uint)puVar2;
        }
        puVar3[1] = param_1[1];
        *(uint *)param_1[1] = (uint)puVar3 | *(uint *)param_1[1] & 3;
        puVar5 = puVar4;
      }
      *puVar3 = *param_1;
      puVar3[2] = param_1[2];
      *(uint *)param_1[2] = (uint)puVar3 | *(uint *)param_1[2] & 3;
      goto joined_r0x0051f480;
    }
    uVar1 = *param_1;
    puVar2 = (uint *)param_1[2];
  }
  puVar5 = (uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 & 1;
  if (puVar2 != (uint *)0x0) {
    *puVar2 = *puVar2 & 3 | (uint)puVar5;
  }
  if (puVar5 == (uint *)0x0) {
    *param_2 = puVar2;
  }
  else if ((uint *)puVar5[2] == param_1) {
    puVar5[2] = (uint)puVar2;
  }
  else {
    puVar5[1] = (uint)puVar2;
  }
joined_r0x0051f480:
  if (uVar1 == 0) {
    return;
  }
  do {
    if (puVar2 == (uint *)0x0) {
      puVar3 = (uint *)*param_2;
    }
    else {
      if ((*puVar2 & 1) == 0) {
        uVar1 = *puVar2;
        goto LAB_0051f700;
      }
      puVar3 = (uint *)*param_2;
    }
    if (puVar2 == puVar3) goto LAB_0051f6f4;
    puVar3 = (uint *)puVar5[2];
    if (puVar3 == puVar2) {
      puVar3 = (uint *)puVar5[1];
      if (puVar3 == (uint *)0x0) {
        return;
      }
      if ((*puVar3 & 1) == 0) {
        *puVar3 = *puVar3 | 1;
        *puVar5 = *puVar5 & 0xfffffffe;
        __rb_rotate_left(puVar5,param_2);
        puVar3 = (uint *)puVar5[1];
      }
      puVar2 = (uint *)puVar3[2];
      if (puVar2 == (uint *)0x0) {
        puVar4 = (uint *)puVar3[1];
      }
      else {
        puVar4 = (uint *)puVar3[1];
        if ((*puVar2 & 1) == 0) goto LAB_0051f5b4;
      }
      if (puVar4 == (uint *)0x0) {
        uVar1 = *puVar3;
      }
      else {
        if ((*puVar4 & 1) == 0) {
          puVar4 = (uint *)puVar3[1];
LAB_0051f5b4:
          if ((puVar4 == (uint *)0x0) || ((*puVar4 & 1) != 0)) {
            if (puVar2 == (uint *)0x0) {
              return;
            }
            *puVar2 = *puVar2 | 1;
            *puVar3 = *puVar3 & 0xfffffffe;
            __rb_rotate_right(puVar3,param_2);
            puVar3 = (uint *)puVar5[1];
            uVar1 = *puVar3;
          }
          else {
            uVar1 = *puVar3;
          }
          *puVar3 = *puVar5 & 1 | uVar1 & 0xfffffffe;
          pcVar6 = __rb_rotate_left;
          *puVar5 = *puVar5 | 1;
          *(uint *)puVar3[1] = *(uint *)puVar3[1] | 1;
LAB_0051f6e8:
          (*pcVar6)(puVar5,param_2);
          puVar2 = (uint *)*param_2;
LAB_0051f6f4:
          if (puVar2 == (uint *)0x0) {
            return;
          }
          uVar1 = *puVar2;
LAB_0051f700:
          *puVar2 = uVar1 | 1;
          return;
        }
        uVar1 = *puVar3;
      }
    }
    else {
      if (puVar3 == (uint *)0x0) {
        return;
      }
      if ((*puVar3 & 1) == 0) {
        *puVar3 = *puVar3 | 1;
        *puVar5 = *puVar5 & 0xfffffffe;
        __rb_rotate_right(puVar5,param_2);
        puVar3 = (uint *)puVar5[2];
      }
      puVar2 = (uint *)puVar3[2];
      if (puVar2 != (uint *)0x0) {
        if ((*puVar2 & 1) != 0) {
          puVar4 = (uint *)puVar3[1];
          goto LAB_0051f500;
        }
        uVar1 = *puVar2;
LAB_0051f65c:
        if ((uVar1 & 1) == 0) {
          uVar1 = *puVar3;
        }
        else {
          puVar2 = (uint *)puVar3[1];
LAB_0051f66c:
          *puVar2 = *puVar2 | 1;
          *puVar3 = *puVar3 & 0xfffffffe;
          __rb_rotate_left(puVar3,param_2);
          puVar3 = (uint *)puVar5[2];
          uVar1 = *puVar3;
        }
        *puVar3 = *puVar5 & 1 | uVar1 & 0xfffffffe;
        pcVar6 = __rb_rotate_right;
        *puVar5 = *puVar5 | 1;
        *(uint *)puVar3[2] = *(uint *)puVar3[2] | 1;
        goto LAB_0051f6e8;
      }
      puVar4 = (uint *)puVar3[1];
LAB_0051f500:
      if (puVar4 == (uint *)0x0) {
        uVar1 = *puVar3;
      }
      else {
        if ((*puVar4 & 1) == 0) {
          if (puVar2 != (uint *)0x0) {
            uVar1 = *puVar2;
            goto LAB_0051f65c;
          }
          puVar2 = (uint *)puVar3[1];
          goto LAB_0051f66c;
        }
        uVar1 = *puVar3;
      }
    }
    *puVar3 = uVar1 & 0xfffffffe;
    puVar2 = puVar5;
    puVar5 = (uint *)(*puVar5 & 0xfffffffc);
  } while( true );
}

