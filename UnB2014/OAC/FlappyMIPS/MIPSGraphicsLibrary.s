.data

points:
	.word 	200, 10
	.word 	170, 40
	.word	240, 60
	.word 	240, 30

.text	

	#Register	|Line		|Rect		|poly		|Circle
	#====================================================================================
	#a0		|x0 co-ord	|x		|points[]	|cx
	#a1		|x1		|y		|count		|cy
	#a2		|y0		|width				|radius
	#a3		|y1		|height	
	#s0		|colour		|colour		|colour		|colour
	
	
	
	addi	$a0, $0, 50			#x
	addi	$a1, $0, 10			#y
	addi	$a2, $0, 40			#width
	addi	$a3, $0, 20			#height
	addi 	$s0, $0, 0x000000FF
	
	jal 	DrawRect
	nop
	
	
	
	addi	$a0, $0, 280			#x = 280
	addi	$a1, $0, 140			#y = 140	
	addi	$a2, $0, 30			#r = 30
	addi 	$s0, $0, 0x0052F5FF
	
	jal 	DrawCircle
	nop
	
	addi	$a0, $0, 380			#x0
	addi	$a1, $0, 420			#x1
	addi	$a2, $0, 25			#y0
	addi	$a3, $0, 225			#y1
	addi 	$s0, $0, 0x00FF9933
	
	jal 	DrawLine
	nop
	
	
	li   	$v0, 10         	
      	syscall
     
#############################################################################################################################################
#Method for drawing a filled circle
#Bresenham Circle Algorithm (modified to use lines)
#Method is similar to the drawCircle method except instead of plotting 4 points, draws the lines between them
FillCircle:
	#a0 = cx
	#a1 = cy
	#a2 = radius
	#s0 = colour
	
	addiu	$sp, $sp, -40
	sw 	$ra, 36($sp)
	sw	$a0, 32($sp)
	sw	$a1, 28($sp)
	sw	$a2, 24($sp)
	sw	$s6, 20($sp)
	sw	$s5, 16($sp)
	sw	$s4, 12($sp)
	sw	$s3, 8($sp)
	sw	$s2, 4($sp)
	sw	$s0, ($sp)
	
	sub	$s2, $0, $a2			#error =  -radius
	add	$s3, $0, $a2			#x = radius
	add	$s4, $0, $0			#y = 0 (s4)
	
	FillCircleLoop:
	bgt 	$s4, $s3, exitFillCircle	#if y is greater than x, break the loop (while loop x >= y)
	nop
	
	jal	draw4lines
	nop
	
	add	$s2, $s2, $s4			#error += y
	addi	$s4, $s4, 1			#++y
	add	$s2, $s2, $s4			#error += y
	
	blt	$s2, 0, FillCircleLoop		#if error >= 0, start loop again
	nop
	
	sub	$s3, $s3, 1			#--x
	sub	$s2, $s2, $s3			#error -= x
	sub	$s2, $s2, $s3			#error -= x
	
	j	FillCircleLoop
	nop	
	
	exitFillCircle:
	
	lw	$s0, ($sp)
	lw	$s2, 4($sp)
	lw	$s3, 8($sp)
	lw	$s4, 12($sp)
	lw	$s5, 16($sp)
	lw	$s6, 20($sp)
	lw	$a2, 24($sp)
	lw	$a1, 28($sp)
	lw	$a0, 32($sp)
	lw	$ra, 36($sp)
	
	addiu	$sp, $sp, 40
	
	jr 	$ra
	nop
	
draw4lines:
	addiu	$sp, $sp -4
	sw	$ra, ($sp)
	
	jal	draw2lines
	nop
	
	beq 	$s4, $s3, fillskipSecondplot
	nop
	
	#swap y and x, and do it again
	add	$t5, $0, $s4			#puts y into t2
	add	$s4, $0, $s3			#puts x in to y
	add	$s3, $0, $t5			#puts y in to x
	
	jal	draw2lines
	nop
	
	#swap them back
	add	$t5, $0, $s4			#puts y into t2
	add	$s4, $0, $s3			#puts x in to y
	add	$s3, $0, $t5			#puts y in to x
		
	fillskipSecondplot:
		
	lw	$ra, ($sp)
	addiu	$sp, $sp, 4
	
	jr	$ra
	nop
	
draw2lines:

	addiu	$sp, $sp -16
	sw	$a1, 12($sp)
	sw	$a0, 8($sp)
	sw	$t5, 4($sp)
	sw	$ra, ($sp)
	
	
	#$a0 = a0 + s3, $a2 = a1 + s4
	add	$s5, $0, $a0			#store a0 (cx in t0)
	add	$s6, $0, $a1			#store a1 (cy in t1)
	
	add	$a0, $s5, $s3			#set a0 (x for the setpixel, to cx + x)
	add	$a2, $s6, $s4			#set a2 (y for setPixel to cy + y)	
	
	sub	$a1, $s5, $s3			#cx - x
	sub	$a3, $s6, $s4			#(cy-y)
	
	jal 	DrawLine			#Draws the first line
	nop	

	add	$a0, $s5, $s3			#(cx+x)
	sub	$a2, $s6, $s4			#(cy-y)
	
	sub	$a1, $s5, $s3			#cx - x
	add	$a3, $s6, $s4			#cy + y
	
	jal	DrawLine			#draws the second line
	nop
	
	add	$a0, $0, $s5			#local variables are used to store the original cx and cy values
	add	$a2, $0, $s6			#
	
	
	lw	$ra, ($sp)
	lw	$t5, 4($sp)
	lw	$a0, 8($sp)
	lw	$a1, 12($sp)
	addiu	$sp, $sp, 16
	
	jr	$ra
	nop
      	
 	
#############################################################################################################################################
#Method for drawing an outline of a circle
#Bresenham Circle Algorithm
#this function uses 2 sub methods to plot points around the circle
#plot8points calls plot4points twice but swapping the x and y in order draw the opposite side of the circle

DrawCircle:
	#a0 = cx
	#a1 = cy
	#a2 = radius
	#s0 = colour
	
	addiu	$sp, $sp, -32
	sw 	$ra, 28($sp)
	sw	$a0, 24($sp)
	sw	$a1, 20($sp)
	sw	$a2, 16($sp)
	sw	$s4, 12($sp)
	sw	$s3, 8($sp)
	sw	$s2, 4($sp)
	sw	$s0, ($sp)
	
	#code goes here
	sub	$s2, $0, $a2			#error =  -radius
	add	$s3, $0, $a2			#x = radius
	add	$s4, $0, $0			#y = 0 (s4)
	
	DrawCircleLoop:
	bgt 	$s4, $s3, exitDrawCircle	#if y is greater than x, break the loop (while loop x >= y)
	nop
	
	#plots 4 points along the right of the circle, then swaps the x and y and plots the opposite 4 points
	jal	plot8points
	nop
	
	add	$s2, $s2, $s4			#error += y
	addi	$s4, $s4, 1			#++y
	add	$s2, $s2, $s4			#error += y
	
	blt	$s2, 0, DrawCircleLoop		#if error >= 0, start loop again
	nop
	
	sub	$s3, $s3, 1			#--x
	sub	$s2, $s2, $s3			#error -= x
	sub	$s2, $s2, $s3			#error -= x
	
	j	DrawCircleLoop
	nop	
	
	exitDrawCircle:
	
	lw	$s0, ($sp)
	lw	$s2, 4($sp)
	lw	$s3, 8($sp)
	lw	$s4, 12($sp)
	lw	$a2, 16($sp)
	lw	$a1, 20($sp)
	lw	$a0, 24($sp)
	lw	$ra, 28($sp)
	
	addiu	$sp, $sp, 32
	
	jr 	$ra
	nop
	
plot8points:
	addiu	$sp, $sp -4
	sw	$ra, ($sp)
	
	jal	plot4points
	nop
	
	beq 	$s4, $s3, skipSecondplot
	nop
	
	#swap y and x, and do it again
	add	$t2, $0, $s4			#puts y into t2
	add	$s4, $0, $s3			#puts x in to y
	add	$s3, $0, $t2			#puts y in to x
	
	jal	plot4points
	nop
	
	#swap them back
	add	$t2, $0, $s4			#puts y into t2
	add	$s4, $0, $s3			#puts x in to y
	add	$s3, $0, $t2			#puts y in to x
		
	skipSecondplot:
		
	lw	$ra, ($sp)
	addiu	$sp, $sp, 4
	
	jr	$ra
	nop
	
plot4points:
	#plots 4 points along the right side of the circle, then swaps the cd and cy values to do the opposite side
	#if statements are for optimisation, they work if the branches are removed
	addiu	$sp, $sp -4
	sw	$ra, ($sp)
	
	#$a0 = a0 + s3, $a2 = a1 + s4
	add	$t0, $0, $a0			#store a0 (cx in t0)
	add	$t1, $0, $a1			#store a2 (cy in t1)
	
	add	$a0, $t0, $s3			#set a0 (x for the setpixel, to cx + x)
	add	$a2, $t1, $s4			#set a2 (y for setPixel to cy + y)
	
	jal	SetPixel			#draw the first pixel
	nop
	
	sub	$a0, $t0, $s3			#cx - x
	#add	$a2, $t1, $s4			#cy + y
	
	beq	$s3, $0, skipXnotequal0 	#if s3 (x) equals 0, skip
	nop
	
	jal 	SetPixel			#if x!=0 (cx - x, cy + y)
	nop	

	skipXnotequal0:	
	sub	$a2, $t1, $s4			#cy - y (a0 already equals cx - x
	jal 	SetPixel			#no if	 (cx - x, cy - y)
	nop
	
	add	$a0, $t0, $s3
	
	beq	$s4, $0, skipYnotequal0 	#if s4 (y) equals 0, skip
	nop
	
	jal	SetPixel			#if y!=0 (cx + x, cy - y)
	nop
	
	skipYnotequal0:
	
	add	$a0, $0, $t0			
	add	$a2, $0, $t1			
	
	lw	$ra, ($sp)
	addiu	$sp, $sp, 4
	
	jr	$ra
	nop

##############################################################################################################################################
#Takes in a register which points to a data segment in memory
#because .data is store in 0x10010000 ive had to change at which location the set pixels are drawn
#iterates the number of times allocated in count (a1) using lw to retrieve the information and printing the lines
#once it hits the number of iterations, it moves the stack pointer 8 * count backwards to point to the original values
DrawPoly:
	addiu	$sp, $sp, -28
	sw	$ra, 24($sp)
	sw	$a0, 20($sp)
	sw	$a1, 16($sp)
	sw	$s4, 12($sp)
	sw	$s3, 8($sp)
	sw	$s2, 4($sp)
	sw	$s0, ($sp)
	
	#code goes here				#a0 holds the address of the current element, a1 holds the number of elements
	add 	$s2, $0, $a0			#s0 is colour, #s2 is memory address of pixels
	add	$s3, $0, $a1			#number of elements now in s3
	addi	$s4, $0, 1			#iterator
	#lw	$s5, 0				#offset
	
	drawNextLineinPoly:
	bgt	$s4, $s3, exitDrawPoly
	#this will go through each word in the array, s2 is used as the pointer for the elements
	
	lw 	$a0, ($s2)			#load the contents of the first value into a0 (x0)
	addi	$s2, $s2, 4			#increment the offset by 4, as to point t othe next point
	
	lw	$a2, ($s2)			#load contents of the Y into a2 (y0)
	addi	$s2, $s2, 4			#increment offset
	
	#check, if iterator is equal to count, do 8(2 lots of 4 bytes) * count, and minus from the pointer (s2)
	bne 	$s4, $s3, skipIteratorCheck
	nop
	
	add	$t9, $0, $s3			#set count to t9
	sll	$t9, $t9, 3			#multiplies by 8
	
	sub	$s2, $s2, $t9			#sub that from pointer	
	addi	$t9, $0, 0 			#set t9 back to 0 for later use
	
	
	skipIteratorCheck:
	lw	$a1, ($s2)			#a1 is x1
	addi	$s2, $s2, 4
	
	lw	$a3, ($s2)			#a3 is y1
	addi	$s2, $s2, -4			#after its loaded, goes back to the previous X
	
	addi	$s4, $s4, 1			#increment iterator by 1
	
	jal	DrawLine			#draw line
	nop
	
	j	drawNextLineinPoly
	nop
	
	exitDrawPoly:
	
	lw	$s0, ($sp)
	lw	$s2, 4($sp)
	lw	$s3, 8($sp)
	lw	$s4, 12($sp)
	lw	$a1, 16($sp)
	lw	$a0, 20($sp)
	lw	$ra, 24($sp)
	
	addiu	$sp, $sp, 28
	
	jr 	$ra
	nop
	
##############################################################################################################################################
#Simply takes the x and y poisition and draws a line from the left of the rectangle to the right of the rectangle
# The Y of the lines are incremented by 1 each time
#once the line y is equal to the height + rectangles y poition, it breaks out of the loop

FillRect:	#a0 = x, a1 = y, a2 = width, a3 = height, s0 = colour
	addiu 	$sp, $sp, -36
	sw	$ra, 32($sp)			#return address
	sw	$a0, 28($sp)			#x
	sw	$a1, 24($sp)			#y
	sw	$a2, 20($sp)			#width
	sw	$a3, 16($sp)			#height
	sw	$s2, 12($sp)
	sw	$s3, 8($sp)
	sw	$s4, 4($sp)
	sw	$s0, ($sp)			#colour
	
	add	$s2, $0, $a2			#width now in s2
	add	$s3, $0, $a3			#height now in s3
	
	#a0 is already x0
	add	$a2, $0, $a1			#y0 is assigned
	
	add	$a1, $a0, $s2			#a1 which is x1 is equal to x + width
	add	$a3, $0, $a2			#first line, Ys are same
	
	add	$s4, $s3, $a2			#where the line needs to draw to (height + y position)
	
	fillRectLoop:
	
	jal	DrawLine			#draw line
	nop

	bge	$a2, $s4, exitFillRect		#check if either of the Y's are equal to the height (s3)
	nop
	
	addi	$a2, $a2, 1			#increment by Y's by one
	addi	$a3, $a3, 1
		
	j	fillRectLoop
	nop
	
	exitFillRect:
	
	lw	$s0, ($sp)			#return values from the stack
	sw	$s4, 4($sp)	
	sw	$s3, 8($sp)
	sw	$s2, 12($sp)
	lw	$a3, 16($sp)
	lw	$a2, 20($sp)
	lw	$a1, 24($sp)
	lw	$a0, 28($sp)
	lw	$ra, 32($sp)
	
	addiu	$sp, $sp, 36
	
	jr	$ra
	nop

      	
###############################################################################################################################################
      	
#takes in the x, y, width and height and then calculates the lines that are needed to draw it
#Uses no loops, simply works out and draws one line at a time

DrawRect:	#a0 = x, a1 = y, a2 = width, a3 = height, s0 = colour
	addiu 	$sp, $sp, -32
	sw	$ra, 28($sp)			#return address
	sw	$a0, 24($sp)			#x
	sw	$a1, 20($sp)			#y
	sw	$a2, 16($sp)			#width
	sw	$a3, 12($sp)			#height
	sw	$s2, 8($sp)	
	sw	$s3, 4($sp)
	sw	$s0, ($sp)			#colour
	
	add	$s2, $0, $a2			#width now in s2
	add	$s3, $0, $a3			#height now in s3

	
	#a0 is already x0
	add	$a2, $0, $a1			#y0 is assigned
	
	add	$a1, $a0, $s2			#a1 which is x1 is equal to x + width
	add	$a3, $0, $a2			#first line, Ys are same

	jal	DrawLine			#Draws top left to top right
	nop
	
	#now i need to change a0 and y0 to be the next point
	
	add	$a0, $0, $a1			#X's are the same
	add	$a2, $a3, $s3			#y0 is now y + height
	
	jal	DrawLine			#draws top right to bottom right
	nop
	
	#x1 and y1 now need to change (a1 + a3)
	
	add	$a3, $0, $a2			#Y's are the same
	sub	$a1, $a0, $s2			#x1 (a1) is now x - width
	
	jal	DrawLine			#draws bottom right to bottom left
	nop
	
	#Final Line, Need to change a0 and a2 (x0, y0)
	
	add	$a0, $0, $a1			#Y's are the same
	sub	$a2, $a2, $s3			#x1 (a1) is now x - width
	
	jal	DrawLine			#draws bottom left to top left
	nop
	
	
	lw	$s0, ($sp)			#return values from the stack
	sw	$s3, 4($sp)
	sw	$s2, 8($sp)
	lw	$a3, 12($sp)
	lw	$a2, 16($sp)
	lw	$a1, 20($sp)
	lw	$a0, 24($sp)
	lw	$ra, 28($sp)
	
	addiu	$sp, $sp, 32
	
	jr	$ra
	nop

######################################################################################################################################################	
#works out the gradiant of the line, adding it each time it draws a new pixel until the x and y co-ordinates
#mattch those of the second point			
									
DrawLine:	#a0 = x0, a1 = x1, a2 = y0, a3 = y1, s0 = colour
	addiu 	$sp, $sp, -24
	sw	$ra, 20($sp)			#return address
	sw	$a0, 16($sp)			#x0
	sw	$a1, 12($sp)			#x1
	sw	$a2, 8($sp)			#y0
	sw	$a3, 4($sp)			#y1
	sw	$s0, ($sp)			#colour
		
	sub	$t0, $a1, $a0			# dx = x1 - x0 ($t0 == dx)
	sub	$t1, $a3, $a2			# dy = y1 - y0 ($t1 == dy)
	abs 	$t0, $t0			# absolute value of dx (so its always positive)
	abs	$t1, $t1			# aboslute value of dy 
	

	blt 	$a0, $a1, skipsx
	addi	$t2, $0, 1			# sx = 1 (t2 == sx)
	addi	$t2, $0, -1			# sx = -1 (skipped is above condition is true)
	
	skipsx:
	blt 	$a2, $a3, skipsy
	addi	$t3, $0, 1			# sy = 1 (t3 == sy)
	addi	$t3, $0, -1			# sy = -1 (skipped is above condition is true)
	
	skipsy:					#$t4 = err
	sub	$t4, $t0, $t1			# err = dx ($t0) - dy ($t1)
	
	drawlineloop:
	jal 	SetPixel			#draws a pixel
	nop
	
	#set if equal to, if r1 = r2 then set r3 to 1, else 0     seq r3, r1, r2
	seq 	$t7, $a0, $a1			#if x0 = x1, t7 == 1
	bne	$t7, 1, skipexitcheck
	nop
	
	seq	$t8, $a2, $a3			#if y0 == y1
	
	#if t7 == 1 and t8 == 1 (this will only be called when t7 is 1, so we only check if t8 is aswell
	beq 	$t7, $t8, exit_drawline
	nop
	
	# i can reuse t7 and t8 if i need to
	skipexitcheck:	
	add	$t5, $t4, $t4			#add err to err and store in $t5 (t5 == e2) (err + err) == (err * 2)
	
	#if (e2 > -dy)
	sub 	$t6, $0, $t1			#$t6 = (0 - dy) thus -dy
						#if not less than or equal to is the same as greater than
	ble 	$t5, $t6, skipdy
	nop
	
	add	$t4, $t4, $t6			#err ($t4) = err + -dy ($t6)
	add	$a0, $a0, $t2			#x0 (a0) = x0 + sx ($t2)
	
	j	drawlineloop
	nop
	
	skipdy:
	#if not greater than or equal to is the same as less than
	bge	$t5, $t0, skipdx		#if $t5 (e2) is not greater than or equal to (less than) dx ($t0) skip dx
	nop 
	
	add	$t4, $t4, $t0
	add	$a2, $a2, $t3
	
	j	drawlineloop
	nop	
	
	
	skipdx:
		
	exit_drawline:
	lw	$s0, ($sp)
	lw	$a3, 4($sp)
	lw	$a2, 8($sp)
	lw	$a1, 12($sp)
	lw	$a0, 16($sp)
	lw	$ra, 20($sp)
	
	addiu	$sp, $sp, 24
	
	jr	$ra
	nop
######################################################################################################################################################	
#Similar to DrawLine method except it only draws the pixel once every other pixel, giving a dotted effect		
DrawDottedLine:	#a0 = x0, a1 = x1, a2 = y0, a3 = y1, s0 = colour
	addiu 	$sp, $sp, -24
	sw	$ra, 20($sp)			#return address
	sw	$a0, 16($sp)			#x0
	sw	$a1, 12($sp)			#x1
	sw	$a2, 8($sp)			#y0
	sw	$a3, 4($sp)			#y1
	sw	$s0, ($sp)			#colour
	
	sub	$t0, $a1, $a0			# dx = x1 - x0 ($t0 == dx)
	sub	$t1, $a3, $a2			# dy = y1 - y0 ($t1 == dy)
	abs 	$t0, $t0			# absolute value of dx (so its always positive)
	abs	$t1, $t1			# aboslute value of dy 
	
	addi	$t9, $0, 1			#set iterator to 1

	blt 	$a0, $a1, skipsxdotted
	addi	$t2, $0, 1			# sx = 1 (t2 == sx)
	addi	$t2, $0, -1			# sx = -1 (skipped is above condition is true)
	
	skipsxdotted:
	blt 	$a2, $a3, skipsydotted
	addi	$t3, $0, 1			# sy = 1 (t3 == sy)
	addi	$t3, $0, -1			# sy = -1 (skipped is above condition is true)
	
	skipsydotted:				#$t4 = err
	sub	$t4, $t0, $t1			# err = dx ($t0) - dy ($t1)
	
	drawdottedlineloop:
	blt    	$t9, 5,  skipdrawpixel		#3 = gap between pixels
	addi	$t9, $t9, 1			#increment iterator in delayed branch slot
	
	addi	$t9, $0, 1			#if itis equal to or less than 0, it will draw the pixel and reset iterator to 1
	jal 	SetPixel			#draws a pixel
	nop
	
	skipdrawpixel:

	#set if equal to, if r1 = r2 then set r3 to 1, else 0     seq r3, r1, r2
	seq 	$t7, $a0, $a1			#if x0 = x1, t7 == 1
	bne	$t7, 1, skipexitcheckdotted
	nop
	
	seq	$t8, $a2, $a3			#if y0 == y1
	
	#if t7 == 1 and t8 == 1 (this will only be called when t7 is 1, so we only check if t8 is aswell
	beq 	$t7, $t8, exit_drawdottedline
	nop
	
	# i can reuse t7 and t8 if i need to
	skipexitcheckdotted:		
	add	$t5, $t4, $t4			#add err to err and store in $t5 (t5 == e2) (err + err) == (err * 2)
	
	#if (e2 > -dy)
	sub 	$t6, $0, $t1			#$t6 = (0 - dy) thus -dy
	#if not less than or equal to is the same as greater than
	ble 	$t5, $t6, skipdydotted
	nop
	
	add	$t4, $t4, $t6			#err ($t4) = err + -dy ($t6)
	add	$a0, $a0, $t2			#x0 (a0) = x0 + sx ($t2)
	
	j	drawdottedlineloop
	nop
	
	skipdydotted:
	#if not greater than or equal to is the same as less than
	bge	$t5, $t0, skipdxdotted		#if $t5 (e2) is not greater than or equal to (less than) dx ($t0) skip dx
	nop 
	
	add	$t4, $t4, $t0
	add	$a2, $a2, $t3
	
	j	drawdottedlineloop
	nop	
	
	
	skipdxdotted:
		
	exit_drawdottedline:
	lw	$s0, ($sp)
	lw	$a3, 4($sp)
	lw	$a2, 8($sp)
	lw	$a1, 12($sp)
	lw	$a0, 16($sp)
	lw	$ra, 20($sp)
	
	addiu	$sp, $sp, 24
	
	jr	$ra
	nop
	
######################################################################################################################################################	
#Similar to DrawLine method except it doesnt draw the pixel onces every 5 iterations, giving a broken line or "dashed" effect	
			
DrawDashedLine:	#a0 = x0, a1 = x1, a2 = y0, a3 = y1, s0 = colour
	addiu 	$sp, $sp, -24
	sw	$ra, 20($sp)			#return address
	sw	$a0, 16($sp)			#x0
	sw	$a1, 12($sp)			#x1
	sw	$a2, 8($sp)			#y0
	sw	$a3, 4($sp)			#y1
	sw	$s0, ($sp)			#colour
	
	sub	$t0, $a1, $a0			# dx = x1 - x0 ($t0 == dx)
	sub	$t1, $a3, $a2			# dy = y1 - y0 ($t1 == dy)
	abs 	$t0, $t0			# absolute value of dx (so its always positive)
	abs	$t1, $t1			# aboslute value of dy 
	
	addi	$t9, $0, 1			#set iterator to 1

	blt 	$a0, $a1, skipsxdashed
	addi	$t2, $0, 1			# sx = 1 (t2 == sx)
	addi	$t2, $0, -1			# sx = -1 (skipped is above condition is true)
	
	skipsxdashed:
	blt 	$a2, $a3, skipsydashed
	addi	$t3, $0, 1			# sy = 1 (t3 == sy)
	addi	$t3, $0, -1			# sy = -1 (skipped is above condition is true)
	
	skipsydashed:				#$t4 = err
	sub	$t4, $t0, $t1			# err = dx ($t0) - dy ($t1)
	
	drawdashedlineloop:
	beq    	$t9, 4,  skipdashpixel		#3 = gap between pixels
	addi	$t9, $t9, 1			#increment iterator in delayed branch slot	
			
			
	jal 	SetPixel			#draws a pixel
	nop
	j	skipreset
	nop
	
	skipdashpixel:
	addi	$t9, $0, 1
	
	skipreset:
	#set if equal to, if r1 = r2 then set r3 to 1, else 0     seq r3, r1, r2
	seq 	$t7, $a0, $a1			#if x0 = x1, t7 == 1
	bne	$t7, 1, skipexitcheckdashed
	nop
	
	seq	$t8, $a2, $a3			#if y0 == y1
	
	#if t7 == 1 and t8 == 1 (this will only be called when t7 is 1, so we only check if t8 is aswell
	beq 	$t7, $t8, exit_drawdashedline
	nop
	
	# i can reuse t7 and t8 if i need to
	skipexitcheckdashed:	
	add	$t5, $t4, $t4			#add err to err and store in $t5 (t5 == e2) (err + err) == (err * 2)
	
	#if (e2 > -dy)
	sub 	$t6, $0, $t1			#$t6 = (0 - dy) thus -dy
	#if not less than or equal to is the same as greater than
	ble 	$t5, $t6, skipdydashed
	nop
	
	add	$t4, $t4, $t6			#err ($t4) = err + -dy ($t6)
	add	$a0, $a0, $t2			#x0 (a0) = x0 + sx ($t2)
	
	j	drawdashedlineloop
	nop
	
	skipdydashed:
	#if not greater than or equal to is the same as less than
	bge	$t5, $t0, skipdxdashed		#if $t5 (e2) is not greater than or equal to (less than) dx ($t0) skip dx
	nop 
	
	add	$t4, $t4, $t0
	add	$a2, $a2, $t3
	
	j	drawdashedlineloop
	nop	
	
	
	skipdxdashed:
		
	exit_drawdashedline:
	lw	$s0, ($sp)
	lw	$a3, 4($sp)
	lw	$a2, 8($sp)
	lw	$a1, 12($sp)
	lw	$a0, 16($sp)
	lw	$ra, 20($sp)
	
	addiu	$sp, $sp, 24
	
	jr	$ra
	nop

############################################################################################################################	
	
SetPixel:
	#a0 x
	#a1 y
	#s0 colour
	addiu	$sp, $sp, -20			# Save return address on stack
	sw	$ra, 16($sp)
	sw	$s1, 12($sp)
	sw	$s0, 8($sp)			# Save original values of a0, s0, a2
	sw	$a0, 4($sp)
	sw	$a2, ($sp)

	lui	$s1, 0x1004			#starting address of the screen	
	sll	$a0, $a0, 2 			#multiply 4
	add	$s1, $s1, $a0			#x co-ord addded to pixel position
	mul  	$a2, $a2, $s7			#multiply by width (s7 declared at top of program, never saved and loaded and it should never be changed)
	mul	$a2, $a2, 4			#myltiply by the size of the pixels (4)
	add	$s1, $s1, $a2			#add y co-ord to pixel position

	sw	$s0, ($s1)			#stores the value of colour into the pixels memory address
	
	lw	$a2, ($sp)			#retrieve original values and return address
	lw	$a0, 4($sp)
	lw	$s0, 8($sp)
	lw	$s1, 12($sp)
	lw	$ra, 16($sp)
	addiu	$sp, $sp, 20	
	
	jr	$ra
	nop
	
