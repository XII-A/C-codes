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

void printAll(struct nodeClass * head){
	
	struct nodeStudent *temp = NULL;
	while (head != NULL)
	{
		printf("%d %.2f\n",head->classID,head->classMidtermAverage);
		if (head->studentPtr != NULL)
		{
			temp = head->studentPtr;
			while (temp != NULL)
			{
				printf("%d %d\n",temp->studentID,temp->midterm);
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
		//End of if null----------------------------------------
    }else
    {
        struct nodeStudent *ptr = NULL;
        struct nodeStudent *Bptr = NULL;
        struct nodeClass *class = (*head);
        int change = 0;
        int i;

        //Creating student--------------------------------
		struct nodeStudent *newStudent = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
		newStudent->studentID = id;
		newStudent->midterm = midterm;
		newStudent->next = NULL;
		//---------------------------------------------------------
        
        //Getting the head of the student linked list-------------------------
        int class_Num = (id/10000)-5;

        if (class_Num == 1)
        {
            ptr = (*head)->studentPtr;
        }else
		{
			for ( i = 1; i < class_Num; i++)
			{
				class = class->next;
			}
			ptr = class->studentPtr;
			
		}
        //----------------------------------------------------------------------

        if (ptr == NULL)
        {
            class->studentPtr = newStudent;
        }else
        {
            while (ptr->next != NULL)
            {
                //In the beginning-----------
                if (newStudent->midterm >= ptr->midterm && Bptr == NULL)
                {
                    if (newStudent->midterm == ptr->midterm)
                    {
                        if (newStudent->studentID < ptr->studentID)
                        {
                            newStudent->next = ptr;
                            class->studentPtr = newStudent;
                            change = 1;
                            break;
                        }else
                        {
                            ptr->next = newStudent;
                            change = 1;
                            break;
                        }
                        
                        
                    }else
                    {
                        
                        newStudent->next = ptr;
                        class->studentPtr = newStudent;
                        change = 1;
                        break;
                    }
                    
                    
                }
                //In the mid--------------
                else if (newStudent->midterm >= ptr->midterm)
                {
                    if (newStudent->midterm == ptr->midterm)
                    {
                        if (newStudent->studentID < ptr->studentID)
                        {
                            Bptr->next = newStudent;
                            newStudent->next = ptr;
                            change = 1;
                            break;
                        }else
                        {
                            newStudent->next = ptr->next;
                            ptr->next = newStudent;
                            change = 1;
                            break;
                        }
                        
                    }else
                    {
                        Bptr->next = newStudent;
                        newStudent->next = ptr;
                        change = 1;
                        break;
                    }
                    
                    
                }else{
                    Bptr = ptr;
                    ptr = ptr->next;
                }
                
                
            }
            if (change == 0)
            {
                //in case there was only one node in the beginning(second node)-----------
                
                if (class->studentPtr->next == NULL)
                {
                    //in case the newstudent was bigger than the head
                    if (newStudent->midterm >= ptr->midterm)
                    {
                        if (newStudent->midterm == ptr->midterm)
                        {
                            if (newStudent->studentID < ptr->studentID)
                            {
                                newStudent->next = ptr;
                                class->studentPtr = newStudent;
                                change = 1;
                                
                            }else
                            {
                                ptr->next = newStudent;
                                change = 1;
                                
                            }
                        
                        }else
                        {
                            newStudent->next = ptr;
                            class->studentPtr = newStudent;
                            
                        }
                        

                    }
                    //in case the newstudent was smaller than the head
                    else if (newStudent->midterm <= ptr->midterm)
                    {
                        ptr->next = newStudent;
                    }
                    
                }else
                {
                    //In case we reached the end
                    if (newStudent->midterm >= ptr->midterm)
                    {
                        if (newStudent->midterm == ptr->midterm)
                        {
                            if (newStudent->studentID < ptr->studentID)
                            {
                                Bptr->next = newStudent;
                                newStudent->next = ptr;
                                change = 1;
                               
                            }else
                            {
                                newStudent->next = ptr->next;
                                ptr->next = newStudent;
                                change = 1;
                                
                            }
                        
                        }else{
                            Bptr->next = newStudent;
                            newStudent->next = ptr;
                        }
                    }else if (newStudent->midterm <= ptr->midterm)
                    {
                        ptr->next = newStudent;
                    }
                    
                    
                }
                
                
                
                
            }
            
            
        }
        
        









    }
    




}


void computeClassAverage(struct nodeClass *head){
    
    float class_sum = 0;
    float index = 0;
    
    while (head != NULL)
    {
        
        struct nodeStudent *ptr = head->studentPtr;

        while (ptr != NULL)
        {
            class_sum = class_sum + ptr->midterm;
            index++;
            ptr = ptr->next;
        }
        head->classMidtermAverage = (class_sum)/index;
        class_sum = 0;
        index = 0;
        head = head->next;  
    }
    
} 