; func tdcp_send_response_to_ap @ 0x00511bc8 size=0x3c
  511bc8:	27bdffd0 	addiu	sp,sp,-48
  511bcc:	3c070069 	lui	a3,0x69
  511bd0:	30c6ffff 	andi	a2,a2,0xffff
  511bd4:	afa50010 	sw	a1,16(sp)
  511bd8:	24e78af8 	addiu	a3,a3,-29960
  511bdc:	afa60018 	sw	a2,24(sp)
  511be0:	00002821 	move	a1,zero
  511be4:	00003021 	move	a2,zero
  511be8:	afbf002c 	sw	ra,44(sp)
  511bec:	afa00014 	sw	zero,20(sp)
  511bf0:	0c1442b3 	jal	0x510acc
  511bf4:	afa0001c 	sw	zero,28(sp)
  511bf8:	8fbf002c 	lw	ra,44(sp)
  511bfc:	03e00008 	jr	ra
  511c00:	27bd0030 	addiu	sp,sp,48
