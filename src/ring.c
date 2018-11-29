#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "ring.h"


/*****************************************************************************************************************************************
*@function name:buf_add(buffer *q,uint8_t data)
*@brief:Function to add item to buffer
*The function takes a buffer pointer and the data to be added and completes the operarion returning the result of the operation.It checks
*whether the buffer is full or not.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message saying the operation is a success.
*@param:buffer *q,uint8_t data which is a circular buffer pointer and a unsigned integer type data
*******************************************************************************************************************************************/

error_msg buf_add(buffer *q,uint8_t data){

    if((q->head==(NULL))||(q->tail==(NULL))||(q->buff_point==(NULL)))/*This first if else condition checks whether there
							               is any NULL pointer error present in the CB
								       If there is, it will return a null pointer error*/
	error_message=NULL_Error;




      if(buffer_full(q)==full)
						       /*condition to check to check whether the buffer is full or not.
						         when the buffer is full head coincides with tail and the size is equal to the count
							 the buffer is said to be full
							 the error message of full.*/
	{
		error_message=full;
	}





	else if(((q->head)==(q->tail))&&((q->count)!=(q->size)))/*condition to check to check when the buffer is empty*/
	{


	error_message=success;
	*(q->head)=data;
	printf("Data_header=%d\n",*(q->head));
	if((q->head)==(q->buff_point+q->size-1))		/*if the circular buffer reaches the tip of the allocated memory, it,should
								warp around and reach the base of the allocated memory.Otherwise it may just
								increment towards the limit*/
		{
			 (q->head)=(q->buff_point);
		}
	else
		{
			q->head=q->head+1;			//simply increment
		}
       	 q->count=q->count+1;				//count of the CB is incremented by 1
	}

	else
	{
		error_message=success;
      	        *(q->head)=data;
		if((q->head)==(q->buff_point+q->size-1))/*if the circular buffers head pointer reaches the tip of the allocated memory,itshould
						       warp around and reach the base of the allocated memory.Otherwise it may just
						       increment towards the limit*/
		{
			 (q->head)=(q->buff_point);
		}
		else
		{
			q->head=q->head+1;			//simply increment
		}
		q->count=q->count+1;				//increment the count
	}


	return error_message;


}
/*********************************************************************************************************************************************
*@function name:buf_delete(buffer *q,uint8_t data)
*@brief:Function to remove item to buffer
*The function takes a buffer pointer and the data to be removed and completes the operarion returning the result of the operation.It checks
*whether the buffer is empty.If it is empty it shall return an error message saying the circular buffer is empty.In all other cases the
*function returns a message saying the operation is a success.
*@param:buffer *q,uint8_t data which is a circular buffer pointer and a unsigned integer type variable named data to store the removed item
**********************************************************************************************************************************************/
error_msg buf_delete(buffer *q,uint8_t *data){

    if((q->head==(NULL))||(q->tail==(NULL))||(q->buff_point==(NULL)))/*This first if else condition checks whether there
										     is any NULL pointer error present it will return a null 											pointer error*/
	error_message=NULL_Error;





       if(empty_buffer(q)==empty)
							/*check whether the buffer is empty
						        the error message of full.*/
	{error_message=empty;}




	else if(((q->head)==(q->tail))&&((q->count)==(q->size)))	/*condition to check to check when the buffer is full*/
	{


	error_message=success;
	*data=*(q->tail);;
	if((q->tail)==(q->buff_point+q->size-1))/*if the circular buffers tail pointer reaches the tip of the allocated memory, it,should
						go around and reach the base of the buffer.Otherwise it may just
						increment towards the limit*/
		{
			 (q->tail)=(q->buff_point);
		}
	else
		{
			(q->tail)=(q->tail)+1;			//simply increment the tail
		}
       	 (q->count)=(q->count)-1;				//count of the CB is decremented by 1
	}

	else
	{
	error_message=success;
       	*data=*(q->tail);

		if((q->tail)==(q->buff_point+q->size-1))	/*if the circular buffer reaches the tip of the allocated memory,itshould
								go around and reach the base of the buffer.Otherwise it may just
								increment towards the limit*/
		{
		 	(q->tail)=(q->buff_point);
		}
		else
		{
			(q->tail)=(q->tail)+1;			//simply increment
		}
		(q->count)=(q->count)-1;				//count is decremented by 1
	}


	return error_message;


}

/*********************************************************************************************************************************************
*@function name:buffer_full(buffer *q)
*@brief:Function to remove item to check whether the function is full
*The function takes a buffer pointer.It checks
*whether the buffer is full.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg buffer_full(buffer *q){

	if(((q->count)==(q->size))&&((q->head)==(q->tail)))
		error_message=full;

	else if(((q->count)!=(q->size))&&((q->head)==(q->tail)))
		error_message=empty;

	else if((q->head==NULL)||(q->tail==NULL)||(q->buff_point==NULL))
		error_message=NULL_Error;

	else
		error_message=success;


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:buffer_full(buffer *q)
*@brief:Function to remove item to check whether the function is empty
*The function takes a buffer pointer.It checks
*whether the buffer is empty.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg empty_buffer(buffer *q){

	if(((q->count)==(q->size))&&((q->head)==(q->tail)))
		error_message=full;

	else if(((q->count)!=(q->size))&&((q->head)==(q->tail)))
		error_message=empty;

	else if((q->head==NULL)||(q->tail==NULL)||(q->buff_point==NULL))
		error_message=NULL_Error;

	else
		error_message=success;


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:init(buffer *q,size_t size)
*@brief:Function to initalize a Circular buffer
*The function takes a buffer pointer and the size of the buffer
*function returns a message or an error code.
*@param:buffer *q
*@return:error_msg, an enum which returns the data type.
**********************************************************************************************************************************************/
error_msg init(buffer *q,size_t size){


	q->size=size;
	q->buff_point=(uint8_t*)malloc(sizeof(uint8_t)*size);
	q->head=q->buff_point;
	q->tail=q->buff_point;
	q->count=0;
	error_message=empty;
	uint8_t* i;
	i=q->buff_point;
	while(i< q->buff_point+q->size){
		if(i==NULL)
		{
			error_message=NULL_Error;
			break;
		}
		i++;
	}


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:remove(buffer *q,size_t size)
*@brief:Function to destroy a Circular buffer
*The function takes a buffer pointer.
*function returns a message or an error code.
*@param:buffer *q
*@return:error_msg, an enum which returns the data type.
*
**********************************************************************************************************************************************/
error_msg remove_buffer(buffer *q){

	uint8_t *p;
	p=q->buff_point;

	while(p!=NULL){

		p=NULL;
		p=p+1;
	}
	error_message=NULL_Error;
	return error_message;
}
