const mongoose = require('mongoose');
const app = require('./app');
const dotenv = require('dotenv');

const url =
  'mongodb+srv://abhijeettrigunait1234:uQ9qzJWzby8rkEoz@cluster12.ae7l7gn.mongodb.net/?retryWrites=true&w=majority';

const connectConfig = {
  useNewUrlParser: true,
  useUnifiedTopology: true
};
dotenv.config({ path: './config.env' });

const port = 8000;

mongoose.connect(url, connectConfig).then(() => {
  app.listen(port, () => {
    console.log('DB Connection succesful');
    console.log(`Server is running in port ${port}...`);
  });
});

// app.listen(port, () => {
//   console.log(`Server is running in port ${port}...`);
// });
