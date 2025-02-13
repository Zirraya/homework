private: System::Void CreateQ_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();	
	errorProvider1->Clear();	

	System::String^ str = System::Convert::ToString(this -> InPutQu -> Text);
		str += " ";
	 int X, at, pos = 0;
	 at = str -> IndexOf(" "); 
	 while (at != -1) { 
		System::String ^ str1 = str->Substring(pos,at-pos); 
		 pos = at + 1;
		 bool res = Int32::TryParse(str1, X);

		 if (!X) {
			 errorProvider1->SetError(InPutQu, "В строке есть не числа");
			 return;
		 }

		 q.Enqueue(X); 
		 at = str -> IndexOf(" ", pos); 
		
	}
	 System::Collections::Generic::Queue<int> buf; 
	 System::String ^ str2 = "";
	 while (q.Count) {
		 buf.Enqueue(q.Peek()); 
		 str2 += System::Convert::ToString(q.Peek()) + " "; 
		 q.Dequeue(); 		
	}
	 while (buf.Count) { 
		 q.Enqueue(buf.Peek()); 
		 buf.Dequeue(); 
		
	}
		 this -> OutPutQu -> Text = str2; 
}