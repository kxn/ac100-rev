; func cw_priv_roaming_calculate_result_free @ 0x005bbc9c size=0xb0
  5bbc9c:	27bdffd0 	addiu	sp,sp,-48
  5bbca0:	afb20024 	sw	s2,36(sp)
  5bbca4:	afbf002c 	sw	ra,44(sp)
  5bbca8:	afb30028 	sw	s3,40(sp)
  5bbcac:	afb10020 	sw	s1,32(sp)
  5bbcb0:	afb0001c 	sw	s0,28(sp)
  5bbcb4:	8c900010 	lw	s0,16(a0)
  5bbcb8:	1200001c 	beqz	s0,0x5bbd2c
  5bbcbc:	00809021 	move	s2,a0
  5bbcc0:	8e04000c 	lw	a0,12(s0)
  5bbcc4:	50800004 	beqzl	a0,0x5bbcd8
  5bbcc8:	8e020010 	lw	v0,16(s0)
  5bbccc:	0c101f7c 	jal	0x407df0
  5bbcd0:	00000000 	nop
  5bbcd4:	8e020010 	lw	v0,16(s0)
  5bbcd8:	00008821 	move	s1,zero
  5bbcdc:	10400010 	beqz	v0,0x5bbd20
  5bbce0:	2413001c 	li	s3,28
  5bbce4:	8e020004 	lw	v0,4(s0)
  5bbce8:	0222102b 	sltu	v0,s1,v0
  5bbcec:	1040000a 	beqz	v0,0x5bbd18
  5bbcf0:	8e040010 	lw	a0,16(s0)
  5bbcf4:	72331002 	mul	v0,s1,s3
  5bbcf8:	00822021 	addu	a0,a0,v0
  5bbcfc:	8c840018 	lw	a0,24(a0)
  5bbd00:	1080fff8 	beqz	a0,0x5bbce4
  5bbd04:	26310001 	addiu	s1,s1,1
  5bbd08:	0c101f7c 	jal	0x407df0
  5bbd0c:	00000000 	nop
  5bbd10:	0816ef3a 	j	0x5bbce8
  5bbd14:	8e020004 	lw	v0,4(s0)
  5bbd18:	0c101f7c 	jal	0x407df0
  5bbd1c:	00000000 	nop
  5bbd20:	0c101f7c 	jal	0x407df0
  5bbd24:	02002021 	move	a0,s0
  5bbd28:	ae400010 	sw	zero,16(s2)
  5bbd2c:	8fbf002c 	lw	ra,44(sp)
  5bbd30:	00001021 	move	v0,zero
  5bbd34:	8fb30028 	lw	s3,40(sp)
  5bbd38:	8fb20024 	lw	s2,36(sp)
  5bbd3c:	8fb10020 	lw	s1,32(sp)
  5bbd40:	8fb0001c 	lw	s0,28(sp)
  5bbd44:	03e00008 	jr	ra
  5bbd48:	27bd0030 	addiu	sp,sp,48
