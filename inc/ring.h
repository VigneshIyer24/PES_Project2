//********************************************************************************************************************************************/

#include<stdio.h>
#include<stdint.h>
/*******************************************************************************************************************************************
*Below the strucutre of a circular buffer has been defined
*The size of each item is of uint8_t
*
*******************************************************************************************************************************************/
typedef struct {
	uint8_t *buff_point;	//pointer to the buffer
	uint8_t *head;		//Where to add an item
	uint8_t *tail;	//Where to remove an item
	size_t  size;		//No. of items allocated to the buffer
	size_t count;	//number of items currently in the buffer
	}buffer;


typedef enum {
	full,
	empty,
	success,
	NULL_Error		//Buffer allocation failure
	}error_msg;

error_msg error_message;
/*********************************************************************************************************************************************
/*********************************************************************************************************************************************
*@function name:buf_add(buffer *q,uint8_t data)
*@brief:Function to add item to buffer
*The function takes a buffer pointer and the data to be added and completes the operarion returning the result of the operation.It checks
*whether the buffer is full or not.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message saying the operation is a success.
*@param:buffer *q,uint8_t data which is a circular buffer pointer and a unsigned integer type data
*@return:error_msg, an enum which returns the data type.
**********************************************************************************************************************************************/
error_msg buf_add(buffer *q,	uint8_t data);


/*********************************************************************************************************************************************
*@function name:buf_delete(buffer *q,uint8_t data)
*@brief:Function to remove item to buffer
*The function takes a buffer pointer and the data to be removed and completes the operarion returning the result of the operation.It checks
*whether the buffer is empty.If it is empty it shall return an error message saying the circular buffer is empty.In all other cases the
*function returns a message saying the operation is a success.
*@param:buffer *q,uint8_t data which is a circular buffer pointer and a unsigned integer type variable named data to store the removed item
*@return:error_msg, an enum which returns the data type.
*
*
**********************************************************************************************************************************************/
error_msg buf_delete(buffer *q,uint8_t *data);


/*********************************************************************************************************************************************
*@function name:buffer_full(buffer *q)
*@brief:Function to remove item to check whether the function is full
*The function takes a buffer pointer.It checks
*whether the buffer is full.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg buffer_full(buffer *q);


/*********************************************************************************************************************************************
*@function name:buffer_full(buffer *q)
*@brief:Function to remove item to check whether the function is empty
*The function takes a buffer pointer.It checks
*whether the buffer is empty.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg empty_buffer(buffer *q);


/*********************************************************************************************************************************************
*@function name:init(buffer *q,size_t size)
*@brief:Function to initalize a Circular buffer
*The function takes a buffer pointer and the size of the buffer
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg init(buffer *q,size_t size);

/*********************************************************************************************************************************************
*@function name:remove_buffer(buffer *q,size_t size)
*@brief:Function to destroy a Circular buffer
*The function takes a buffer pointer.
*function returns a message or an error code.
*@param:buffer *q
**********************************************************************************************************************************************/
error_msg remove_buffer(buffer *q);


