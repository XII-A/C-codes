struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};
//66 CLASS 1 aka head aka newCLASS
//77 class 2 next node
//88 class 3
//99 class 4

void Display(struct nodeClass * head){
	
	struct nodeStudent *temp = NULL;
	while (head != NULL)
	{
		printf("class id:%d\tclass midtermavg:%d\n",head->classID,head->classMidtermAverage);
		if (head->studentPtr != NULL)
		{
			temp = head->studentPtr;
			while (temp != NULL)
			{
				printf("student id:%d\tstudent midterm:%d\n",head->studentPtr->studentID,head->studentPtr->midterm);
				temp = temp->next;
			}
			
		}
		head = head->next;
	}
	
	
}





struct nodeClass *Create_Class(int id){
	struct nodeClass *newCLASS = (struct nodeClass *)malloc(sizeof(struct nodeClass));
	newCLASS->classID = id;
	newCLASS->classMidtermAverage = 0;
	newCLASS->next = NULL;
	newCLASS->studentPtr = NULL;
	return newCLASS;
}




void insert(struct nodeClass **head,int id,int midterm){
	if ((*head)==NULL)
	{
		//creating class 1---------------------------
		(*head) = Create_Class(1);
		struct nodeClass *ptr = (*head);
		//-------------------------------

		//Creating the rest of classes----------------
		int i;
		for ( i = 2; i < 5; i++)
		{
			ptr->next = Create_Class(i);
			ptr = ptr->next;
		}
		//----------------------------------------------

		//Creating student--------------------------------
		struct nodeStudent *newStudent = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
		newStudent->studentID = id;
		newStudent->midterm = midterm;
		newStudent->next = NULL;
		//---------------------------------------------------------
		
		
		//deciding what to do with the given info-------
		int class_Num = (id/10000)-5;
		ptr = (*head);
		if (class_Num == 1)
		{
			ptr->studentPtr = newStudent;
		}else
		{
			for ( i = 1; i < class_Num; i++)
			{
				ptr = ptr->next;
			}
			ptr->studentPtr = newStudent;
			
		}
		//----------------------------------------
		
		
		
		
		
	
	}else{
		int i;
		int class_Num = (id/10000)-5;
		struct nodeStudent *newStudent = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
		newStudent->studentID = id;
		newStudent->midterm = midterm;
		newStudent->next = NULL;
		struct nodeClass *ptr = (*head);
		struct nodeStudent *studptr = NULL;
		struct nodeStudent *prevstudptr = NULL;
		int change = 0;
		//--------------------------case1-----------------------------------------------------
		if (class_Num == 1)
		{
			studptr = ptr->studentPtr;

			if (studptr == NULL)
			{
				studptr = newStudent;
			}else{
				while (studptr->next != NULL)
				{
					if (newStudent->midterm > studptr->midterm && (prevstudptr != NULL))
					{
						newStudent->next = studptr;
						prevstudptr->next = newStudent;
						change = 1;
						break;
					}else if (newStudent->midterm > studptr->midterm)
					{
						newStudent->next = studptr;
						ptr->studentPtr = newStudent;
						change = 1;
						break;
					}else{
						prevstudptr = studptr;
						studptr = studptr->next;
					}
					
					
				}
				if (change == 0)
				{
					if (ptr->studentPtr->next == NULL && newStudent->midterm > ptr->studentPtr->midterm)
					{
						newStudent->next = studptr;
						ptr->studentPtr = newStudent;
		
					}else if (ptr->studentPtr->next == NULL && newStudent->midterm < ptr->studentPtr->midterm)
					{
						ptr->studentPtr->next = newStudent;
					}else{
							if (newStudent->midterm > studptr->midterm)
							{
								prevstudptr->next = newStudent;
								newStudent->next = studptr;
								studptr->next = NULL;
							}else{
								studptr->next = newStudent;
							}
							
					}
					
					
				}
				
				
			}
			





		}else
		{
		//--------------caseotherthan1---------------------------------------------------------
			for ( i = 1; i < class_Num; i++)
			{
				ptr = ptr->next;
			}
			studptr = ptr->studentPtr;
			
			if (studptr == NULL)
			{
				studptr = newStudent;
			}else{
				while (studptr->next != NULL)
				{
					if (newStudent->midterm > studptr->midterm && (prevstudptr != NULL))
					{
						newStudent->next = studptr;
						prevstudptr->next = newStudent;
						change = 1;
						break;
					}else if (newStudent->midterm > studptr->midterm)
					{
						newStudent->next = studptr;
						ptr->studentPtr = newStudent;
						change = 1;
						break;
					}else{
						prevstudptr = studptr;
						studptr = studptr->next;
					}
					
					
				}
				if (change == 0)
				{
					if (ptr->studentPtr->next == NULL && newStudent->midterm > ptr->studentPtr->midterm)
					{
						newStudent->next = studptr;
						ptr->studentPtr = newStudent;
		
					}else if (ptr->studentPtr->next == NULL && newStudent->midterm < ptr->studentPtr->midterm)
					{
						ptr->studentPtr->next = newStudent;
					}else{
							if (newStudent->midterm > studptr->midterm)
							{
								prevstudptr->next = newStudent;
								newStudent->next = studptr;
								studptr->next = NULL;
							}else{
								studptr->next = newStudent;
							}
							
					}
					
					
				}
				
				
			}


			
		}
	}
	
}



